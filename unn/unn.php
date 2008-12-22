#!/usr/local/bin/php
<?php
	$files = array();
	$debug = false;
	foreach ($argv as $arg)
	{
		if ($arg == '-debug')
		{
			$debug = true;
		}
		else
		{
			if ($arg != $argv[0])
			{
				$files[] = $arg;
			}
		}
	}

	if ($debug)
	{
		echo "debug on\n";
	}
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
	if ($debug)
	{
		echo "we are really done\n";
	}
?>