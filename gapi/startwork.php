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
	$shortopts = "a:"		//action [ required ]
	$shortopts .= "u:";	//username [ required ]
	$shortopts .= "n:";	//full name (first last), default: (Scardy Cat)
	$shortopts .= "p:";	//password [ required ] 
	$shortopts .= "h";	//print usage info

	$cli = getopt($shortopts);

	if (!is_null($cli['h']))
	{
		usage();
	}

	$username = (empty($cli['u'])) ? '' : $cli['u'];
	$fullname = (empty($cli['n'])) ? '' : $cli['n'];
	$password = (empty($cli['p'])) ? '' : $cli['p'];

	if (empty($username) || empty($fullname) || empty($password)
	{
		usage();
	}

	// split full name into given and family name
	
	$name = explode(" ", $fullname, 2);

	$service->createUser($username, $name[0], $name[1], $password, null, null)
	function usage()
	{
		echo "Add: -u[sername] username -n[ame] 'full name' -p[assword] password\n";
		die();
	}
?>