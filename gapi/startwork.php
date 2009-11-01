#!/usr/bin/env php

<?php
	require_once 'config.php';
	require_once 'Zend/Loader.php';
	Zend_Loader::loadClass('Zend_Gdata_ClientLogin');
	Zend_Loader::loadClass('Zend_Gdata_Gapps');

	$email="$username@$domain";
	$client = Zend_Gdata_ClientLogin::getHttpClient($email, $password, Zend_Gdata_Gapps::AUTH_SERVICE_NAME);
	$service = new Zend_Gdata_Gapps($client, $domain);

	$service->retrieveUser("eitana");
?>