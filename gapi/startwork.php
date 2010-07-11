#!/usr/bin/env php
<?php
	/*
		This script is designed for corporate or educational users
		of google apps. It lets you add, remove, suspend, or view
		info about users from a command line script. It is best 
		used in conjuction with existing create-a-user scripts for
		other applications.
	*/
	error_reporting(E_ALL ^ (E_NOTICE|E_WARNING));
	define('COLOR_BOLD',1);
	define('COLOR_RED', 31);
	define('COLOR_GREEN', 32);

	// All of these are set in config.php (and thats it)
	// $config['user password domain']
	require_once 'config.php';
	// set the email right here.
	$config['email']= $config['user'].'@'.$config['domain'];
	require_once 'Zend/Loader.php';
	Zend_Loader::loadClass('Zend_Gdata_ClientLogin');
	Zend_Loader::loadClass('Zend_Gdata_Gapps');

	$actions = Array(
		"add" => Array(
			"required_opts" => Array ('u','f','l','p'),
			"help" => "-u username -f first name -l last name -p password"
		),
		"del" => Array(
			"required_opts" => Array ('u'),
			"help" => "-u username"
		),
		"suspend" => Array (
			"required_opts" => Array('u'),
			"help" => "-u username"
		),
		"restore" => Array (
			"required_opts" => Array('u'),
			"help" => "-u username"
		),
		"display" => Array (
			"required_opts" => Array('u'),
			"help" => "-u username"
		),
		"change-name" => Array(
			"required_opts" => Array('u','f','l'),
			"help" => "-u username -f first name -l last name"
		),
		"change-password" => Array(
			"required_opts" => Array('u','p'),
			"help" => "Changes a user's password"
		),
		"force-pw-change" => Array(
			"required_opts" => Array('u'),
			"help" => "-u username",
			"descr" => "Require a user to change the password at next login"
		),		
		"update" => Array(
			"enabled" => false,
			"required_opts" => Array('u'),
			"help" => "-u username ... "
		),
		"list-add" => Array(
			"enabled" => false,
			"required_opts" => Array('u'),
			"help" => "-u username -e listname ",
			"descr" => "Adds username to email list"
		),
		"list-rm" => Array(
			"enabled" => false,
			"required_opts" => Array('u'),
			"help" => "-u username ... -e listname",
			"descr" => "Removed username from email list"
		),
		"list-all-admins" => Array(
			"enabled" => true,
			"required_opts" => Array(),
			"help" => "",
			"descr" => "list all current administrators"
		)
	);

	// short opts == for the api
	// long opts == for the script
	$shortopts = "";
	$shortopts .= "a:";	//action
	$shortopts .= "u:";	//username 
	$shortopts .= "f:";	//First Name
	$shortopts .= "l:";	//Last name 
	$shortopts .= "p:";	//password 
	$shortopts .= "h";	//print usage info

	$longopts = Array ("action:", 'debug', 'verbose','check-config');

	$cli = getopt($shortopts, $longopts);
	if (!is_null($cli['h']))
	{
		usage();
	}

	//convert from getopt moe to useable mode...
	$doWhat = (empty($cli['action'])) ? '' : $cli['action'];
	if (empty($doWhat))
	{
		$doWhat = (empty($cli['a'])) ? '' : $cli['a'];
	}
	$doWhatPrint = colorText(COLOR_GREEN,$doWhat);
	echo "Trying to $doWhatPrint...\n";
	$username = (empty($cli['u'])) ? '' : $cli['u'];
	$name[0] = (empty($cli['f'])) ? '' : $cli['f'];
	$name[1] = (empty($cli['l'])) ? '' : $cli['l'];
	$givepass = (empty($cli['p'])) ? '' : $cli['p'];
	$nickname = (empty($cli['n'])) ? '' : $cli['n'];

	// long opts
	$debug = (array_key_exists('debug',$cli)) ? true : false;
	$verbose = (array_key_exists('verbose',$cli)) ? true : false;
	$check_config = (array_key_exists('check-config',$cli)) ? true : false;

	// act on the long opts
	if ($check_config)
	{
		$email = colorText(1,$config['email']);
		$password = colorText(1,$config['password']);
		echo "Please verify that $email is your email address and that $password is your password\n";
		// we don't go farther than this with check-config
		return;
	}

	if ($debug)
	{
		echo "We are in debug mode. Operations may change output mode\n";
	}
	// if we don't list a valid action
	if (!array_key_exists($doWhat,$actions))
	{
		//show usage...
		usage("dowhat not in array");
	}
	// triple === for null checking
	if ($actions[$doWhat]["enabled"] === false)
	{
		usage("This action is not enabled");
	}
	// check to make sure that all relevent fields are listed...
	foreach ($actions[$doWhat]["required_opts"] as $opt)
	{
		if (empty($cli[$opt]))
		{
			usage("Missing $opt option\n");
		}
	}

	$client = Zend_Gdata_ClientLogin::getHttpClient($config['email'], $config['password'], Zend_Gdata_Gapps::AUTH_SERVICE_NAME);
	$service = new Zend_Gdata_Gapps($client, $config['domain']);

	echo "Editing user:".colorText(COLOR_GREEN,$username)."\n";

	// I think we should move to getting the user object before the case and submitting it after the case
	// This should make it easier to do certain things (like updating an account).
	// Only problem is what if user does not exist?
	try
	{
		switch ($doWhat)
		{
			case 'add':
				$service->createUser($username, $name[0], $name[1], $givepass, null, null);
				break;
			case 'del':
				$service->deleteUser($username);
				break;
			case 'suspend':
				$service->suspendUser($username);
				break;
			case 'restore':
				$service->restoreUser($username);
				break;
			case 'display':
				displayUser($username);
				break;
			case 'force-pw-change':
				$user = $service->retrieveUser($username);
				$user->login->changePasswordAtNextLogin = true;
				$user = $user->save();
				break;
			case 'change-name':
				if ($verbose)
				{
					echo colorText(1,"Before"),":\n";
					displayUser($username);
				}
				$user = $service->retrieveUser($username);
				$user->name->givenName = $name[0];
				$user->name->familyName = $name[1];
				$user = $user->save();
				if ($verbose)
				{
					echo colorText(1,"After"),":\n";
					displayUser($username);
				}
				break;
			case 'change-password':
				$user = $service->retrieveUser($username);
				$user->login->password = $givepass;
				$user = $user->save();
				break;
				
		}			
		echo 	"This appears to have worked...\n";
	}
	catch (Zend_Gdata_Gapps_ServiceException $e)
	{
		if ($e->hasError(Zend_Gdata_Gapps_Error::ENTITY_DOES_NOT_EXIST))
		{
			echo "Our Error encountered: ".colorText(1,"User does not exist")."\n";
		}
		else
		{
			// Outherwise, just print the errors that occured and exit
			foreach ($e->getErrors() as $error)
			{
				echo "Our Error encountered: ".colorText(1,$error->getReason())." (". colorText(1,$error->getErrorCode()).")\n";
			}
		}
		exit();
	}

	function usage($message="")
	{
		global $actions, $doWhat;
		$me = colorText(COLOR_BOLD,basename ( __FILE__ ));
		echo "This file is called $me\n\n";
		foreach ($actions as $key => $params)
		{
			$helpline = $params['help'];
			$sur_text="";
			// triple equals to avoid null
			if ($params['enabled'] === false)
			{	
				$sur_text=colorText(COLOR_RED,'Disabled');
			}
			if (!empty($params['descr']))
			{
				echo $params['descr'] . "\n";
			}
			$key_print = colorText(1,$key);
			// Indicate which action we want to use";
			if ($doWhat == $key)
			{
				$key_print = colorText(COLOR_GREEN,$key);
				$helpline = colorText(COLOR_GREEN,$helpline);
			}
			echo "\t$sur_text [-a|--action] $key_print $helpline\n";
		}
		echo colorText(COLOR_BOLD," \t--check-config")."\t Verifies that your configuration options are correct\n";
		echo colorText(COLOR_BOLD," \t--debug")."\t Prints debugging information\n";
		echo colorText(COLOR_BOLD," \t--verbose")."\t Increases amount of output generated by the script\n";
		if (!empty($message)) {echo "\n". colorText(33,$message)."\n";}
		echo "Please send all bug reports to Eitan Adler\n";
		die();
	}

	function displayUser($username)
	{
		global $service, $debug;
		$user = $service->retrieveUser($username);
		if ($debug)
		{
			var_dump($user);
			return;
		}
		$info['nicks'] = $service->retrieveNicknames($username);
		$info['lists'] = $service->retrieveEmailLists($username);

		echo 'Username: ' . $user->login->userName . "\n";
		echo 'Given Name: ' . $user->name->givenName . "\n";
		echo 'Family Name: ' . $user->name->familyName . "\n";
		echo 'Suspended: ' . ($user->login->suspended ? 'Yes' : 'No') . "\n";
		echo 'Admin: ' . ($user->login->admin ? 'Yes' : 'No') . "\n";
		echo 'Must Change Password: ' .
			($user->login->changePasswordAtNextLogin ? 'Yes' : 'No') . "\n";
		echo 'Has Agreed To Terms: ' .
			($user->login->agreedToTerms ? 'Yes' : 'No') . "\n";
		echo "IP whitelisted: ";
			echo ($user->login->extensionAttributes->ipWhitelisted) ? "Yes" : "No" . "\n";
		echo 'List of Nicknames: ';
			foreach ($info['nicks'] as $nickname)
			{
				echo '  * ' . $nickname->nickname->name . "\n";
			}
		echo "\n";
		echo 'List of Email Lists: ';
			foreach ($info['lists'] as $list)
			{
				echo '  * ' . $list->emailList->name . "\n";
			}
		echo "\n";
		
	}

	function colorText($color,$text)
	{
		return "\033[".$color."m$text\033[0m";
	}
?>
