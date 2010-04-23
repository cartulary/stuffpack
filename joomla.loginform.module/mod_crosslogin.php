<?php
	// no direct access
	defined( '_JEXEC' ) or die( 'Restricted access' );

	require_once( dirname(__FILE__).DS.'helper.php' );
	$crosslogin = modCrossLoginHelper::getForm($params);
	require( JModuleHelper::getLayoutPath('mod_crosslogin');
?>
