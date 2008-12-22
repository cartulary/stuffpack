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
			fwrite(STDERR,"fatal error: $file exists");
		}
		else
		{
			if ($debug)
			{
				echo "starting execution of $file ...";
				echo "we are done";
			}
		}
	}
	if ($debug)
	{
		echo "we are done\n";
	}
?>