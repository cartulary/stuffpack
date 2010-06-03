#!/usr/bin/env php
<?php
	$files = array();
	$debug = false;
	//eliminate calling command from list
	array_shift($argv);
	// loop through the arguments 
	foreach ($argv as $arg)
	{
		if ($arg == '-debug')
		{
			$debug = true;
		}
		else
		{
			$files[] = $arg;
		}
	}
	// loop through the files
	foreach ($files as $file)
	{
		if (file_exists($file))
		{
			fwrite(STDERR,"fatal error: $file exists\n");
		}
		else
		{
			if ($debug)
			{
				echo "starting execution of $file ...\n";
				echo "we are done\n";
			}
		}
	}
?>