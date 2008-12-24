#!/usr/local/bin/php
<?php
	$files = array();
	$debug = false;
	array_shift($argv);
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