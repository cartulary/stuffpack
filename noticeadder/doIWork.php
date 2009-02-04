#!/usr/bin/env php
<?php
	// CMU licence 
	/*
		features to add: make -f override -e;
		
		1.6.1 removed need for using a reference in foreach
		1.6.0,1 added debug text for -x
		1.6.0 allow -x to force writing
		1.5.0,1 always echo start and end
		1.5.0 -f supports multiple files
		1.4.2,1 changed commenting
		1.4.2 write to STDERR instead of using echo
		1.4.1 error on quiet and verbose
		1.4.0 quiet mode added
		1.3.0 one file can work with -f; change to order of debug output
		1.2.1 start/end if not in debug mode
		1.2.0 debugging and base text found on tag
		...
		1.1.0 command line options
		1.0.0 basics
	*/
	/* getopt setup --DO NOT CHANGE */
	$opts = "d:e:f:t:v:qx";
	// -d directory to work in
	// -e extensions to work with
	// -f for using a file instead of a directory
	// -t text to check for add
	// -v verbose (debugging)
	// -q for quiet mode [NO :]
	// -x for force write [NO :]
	$cli = getopt($opts);
	
	/* defaults */
	$dir = (empty($cli['d'])) ? '.' : $cli['d'];  //set the directory to the command line if it exists
	$extensions = (empty($cli['e'])) ? array('') : explode(' ',$cli['e']); //default to no extension
	$clitext = (empty($cli['t'])) ? '' : $cli['t']; //no default copyright
	$debug = $cli['v']; //set the debugging level
	$use_file = (empty($cli['f'])) ? null : $cli['f'];
	$quiet = (is_null($cli['q'])) ? false : true;
	$force = (is_null($cli['x'])) ? false : true;
	echo (!is_null($use_file)&&!empty($cli['d'])) ? "-f overrides -d" : '';
	if ($quiet&&$debug>0) { fwrite(STDERR,"can not be quiet and verbose\n"); die();} 
	$tag = '--NTC--';
	$text = "\n/*$tag\n$clitext*/\n";

	/* include required files */
	require('dir_recurse.php');

	/* list all files in directory */
	$files = (is_null($use_file)) ? directoryUtility::scan($dir) : explode(' ',$use_file); //scan directory for files unless -f is used

	echo "starting...\n";
	/* get rid of the files we don't want */
	foreach($files as $file)
	{
		$filename =file_name($file);
		if ($filename[0] == '.' ||!in_array(file_ext($file),$extensions)||is_dir($file))
		{
			debugEcho ("removing $file\n",2);
			//if file is hidden, ., .., or the file ext is not in the array remove it
		}
		else
		{
			//if we want add it to an array - works better than removing the unwanted ones from some reason
			$okfiles[] = $file;
			debugEcho ("not removing $file\n",2);
		}
	}
	$files = $okfiles;
	foreach($files as $file)
	{
		debugEcho ("checking $file - ");
		$contents = file_get_contents($file);
		$full_text = (strpos($contents, $text)===true) ? 'true': 'false';
		debugEcho("full = $full_text - ",5);
		if($force||strpos($contents, $tag)===false)
		{
			debugEcho ('text not found!'); 
			echo ($force) ? ' - maybe forced - ' : '';
			$fh = fopen($file, 'a'); //open file (append)
			debugEcho (' writing - ');
			fwrite($fh,$text); //append copyright text
			fclose($fh); //close file
			debugEcho ("\n");

		}
		else
		{
			debugEcho ("text found!\n"); //we found the text - no reason to write anything
		}
	}
	echo "...done\n";

	/*
		give function a file name with a . and it will return the part after the LAST . (aka the extension)
	*/
	function file_ext($file)
	{
		return substr(strrchr($file, '.'), 1); 
	}
	
	/*
		give function a path and it will return the value after the LAST / (aka the file name)
	*/
	function file_name($file)
	{
		return substr(strrchr($file, '/'), 1);
	}
	function debugEcho($text,$lvl=1)
	{
		global $debug,$quiet;
		echo (!$quiet&&$debug>=$lvl) ? $text : '';
		echo (!$quiet&&$debug<=0&&$lvl<=0) ? $text : '';
	}
?>
