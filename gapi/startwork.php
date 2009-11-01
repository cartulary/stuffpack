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

	$giveuser = (empty($cli['u'])) ? '' : $cli['u'];
	$fullname = (empty($cli['n'])) ? '' : $cli['n'];
	$givepass = (empty($cli['p'])) ? '' : $cli['p'];

	// split full name into given and family name	
	$name = explode(" ", $fullname, 2);

	if (empty($giveuser) || empty($name[0]) || empty($name[1]) || empty($givepass))
	{
		usage();
	}

	echo "user: $giveuser pass: $givepass\n";
	var_dump($name);
	try
	{
		$service->createUser($giveuser, $name[0], $name[1], $givepass, null, null);
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