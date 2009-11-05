#!/usr/bin/env php
<?php
	// All of these are set in config.php (and thats it)
	// $config['user password domain']
	require_once 'config.php';
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
		)
	);

	// short opts == for the api
	// long opts == for the script
	$shortopts = "";
	$shortopts .= "u:";	//username 
	$shortopts .= "f:";	//First Name
	$shortopts .= "l:";	//Last name 
	$shortopts .= "p:";	//password 
	$shortopts .= "h";	//print usage info

	$longopts = Array ("action:", 'debug');

	$cli = getopt($shortopts, $longopts);
	if (!is_null($cli['h']))
	{
		usage();
	}

	$doWhat = (empty($cli['action'])) ? '' : $cli['action'];
	echo "Trying to $doWhat...\n";
	$username = (empty($cli['u'])) ? '' : $cli['u'];
	$name[0] = (empty($cli['f'])) ? '' : $cli['f'];
	$name[1] = (empty($cli['l'])) ? '' : $cli['l'];
	$givepass = (empty($cli['p'])) ? '' : $cli['p'];

	$debug = (array_key_exists('debug',$cli)) ? true : false;

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

	// check to make sure that all relevent fields are listed...
	foreach ($actions[$doWhat]["required_opts"] as $opt)
	{
		if (empty($cli[$opt]))
		{
			usage("Missing $opt option\n");
		}
	}

	$config['email']= $config['user'].'@'.$config['domain'];
	$client = Zend_Gdata_ClientLogin::getHttpClient($config['email'], $config['password'], Zend_Gdata_Gapps::AUTH_SERVICE_NAME);
	$service = new Zend_Gdata_Gapps($client, $config['domain']);


	echo "Editing user: $username\n";

	// I think we should move to getting the user object before the case and submitting it after the case
	// This should make it easier to do certain things (like updating an account).
	// Only problem is what if user does not exist?
	try
	{
		switch ($doWhat)
		{
			case 'add':
				if (empty($name[0]) || empty($name[1]))
				{
					usage();
				}
				$service->createUser($username, $name[0], $name[1], $givepass, null, null);
				break;
			case 'del':
				$service->deleteUser($username);
				break;
			case 'suspend':
				$service->suspendUser($username);
			case 'restore':
				$service->restoreUser($username);
			case 'display':
				displayUser($username);
				
		}			
		echo 	"This appears to have worked...\n";
	}
	catch (Zend_Gdata_Gapps_ServiceException $e)
	{
		if ($e->hasError(Zend_Gdata_Gapps_Error::ENTITY_DOES_NOT_EXIST))
		{
			echo "Our Error encountered: User does nto exist\n";
		}
		else
		{
			// Outherwise, just print the errors that occured and exit
			foreach ($e->getErrors() as $error)
			{
				echo "Our Error encountered: {$error->getReason()} ({$error->getErrorCode()})\n";
			}
		}
		exit();
	}

	function usage($where="")
	{
		global $actions;
		$me = basename ( __FILE__ );
		foreach ($actions as $key => $params)
		{
			$helpline = $params['help'];
			echo "$key: $me -a $action $helpline\n";
		}
		if (!empty($message)) {echo "Message: $where\n";}
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
?>
