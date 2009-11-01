#!/usr/bin/env php
<?php
	require_once 'config.php';
	require_once 'Zend/Loader.php';
	Zend_Loader::loadClass('Zend_Gdata_ClientLogin');
	Zend_Loader::loadClass('Zend_Gdata_Gapps');

	$email="$username@$domain";
	$client = Zend_Gdata_ClientLogin::getHttpClient($email, $password, Zend_Gdata_Gapps::AUTH_SERVICE_NAME);
	$service = new Zend_Gdata_Gapps($client, $domain);

	$shortopts = "";
	$shortopts = "a:";	//action [ required ]
	$shortopts .= "u:";	//username [ required ]
	$shortopts .= "n:";	//full name (first last), default: (Scardy Cat)
	$shortopts .= "p:";	//password [ required ] 
	$shortopts .= "h";	//print usage info

	$cli = getopt($shortopts);

	if (!is_null($cli['h']))
	{
		usage();
	}

	$doWhat = (empty($cli['a'])) ? '' : $cli['a'];
	$giveuser = (empty($cli['u'])) ? '' : $cli['u'];
	$fullname = (empty($cli['n'])) ? '' : $cli['n'];
	$givepass = (empty($cli['p'])) ? '' : $cli['p'];

	// split full name into given and family name	
	$name = explode(" ", $fullname, 2);

	$actions = Array(
		"add" => Array(
			"required_opts" => Array ("u","n","p")
		),
		"del" => Array(
			"required_opts" => Array ("u")
		)
	);

	// if we don't list a valid action
	if (!in_array($doWhat,$actions))
	{
		//show usage...
		usage();
	}

	// check to make sure that all relevent fields are listed...
	foreach ($actions[$doWhat]["required_opts"] as $opt)
	{
		if (empty($cli[$opt]))
		{
			usage();
		}
	}

	echo "user: $giveuser pass: $givepass\n";
	var_dump($name);
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
				$service->deleteUser($username);
				break;
		}			
		echo "This appears to have worked...";
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

	function usage()
	{
		echo "Add: -u[sername] username -n[ame] 'full name' -p[assword] password\n";
		die();
	}
?>