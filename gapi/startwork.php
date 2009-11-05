#!/usr/bin/env php
<?php
	// All of these are set in config.php (and thats it)
	// username  password domain
	require_once 'config.php';
	require_once 'Zend/Loader.php';
	Zend_Loader::loadClass('Zend_Gdata_ClientLogin');
	Zend_Loader::loadClass('Zend_Gdata_Gapps');

	$email="$username@$domain";
	$client = Zend_Gdata_ClientLogin::getHttpClient($email, $password, Zend_Gdata_Gapps::AUTH_SERVICE_NAME);
	$service = new Zend_Gdata_Gapps($client, $domain);

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

	$longopts = Array ("action:");

	$cli = getopt($shortopts, $longopts);

	if (!is_null($cli['h']))
	{
		usage();
	}

	$doWhat = (empty($cli['action'])) ? '' : $cli['action'];
	echo "Trying to $doWhat...\n";
	$giveuser = (empty($cli['u'])) ? '' : $cli['u'];
	$name[0] = (empty($cli['f'])) ? '' : $cli['f'];
	$name[1] = (empty($cli['l'])) ? '' : $cli['l'];
	$givepass = (empty($cli['p'])) ? '' : $cli['p'];

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

	echo "Editing user: $giveuser\n";
	try
	{
		switch ($doWhat)
		{
			case 'add':
				if (empty($name[0]) || empty($name[1]))
				{
					usage();
				}
				$service->createUser($giveuser, $name[0], $name[1], $givepass, null, null);
				break;
			case 'del':
				$service->deleteUser($giveuser);
				break;
			case 'suspend':
				$service->suspendUser($username);
			case 'restore':
				$service->restoreUser($username);
		}			
		echo "This appears to have worked...\n";
	}
	catch (Zend_Gdata_Gapps_ServiceException $e)
	{
		if ($e->hasError(Zend_Gdata_Gapps_Error::ENTITY_DOES_NOT_EXIST))
		{
			return null;
		}
		else
		{
			// Outherwise, just print the errors that occured and exit
			foreach ($e->getErrors() as $error)
			{
				echo "Error encountered: {$error->getReason()} ({$error->getErrorCode()})\n";
			}
			exit();
		}
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
?>