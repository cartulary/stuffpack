#!/usr/bin/env php
<?
$path = ".";

$dir_handle = @opendir($path) or die("Unable to open $path");

//running the while loop
while ($file = readdir($dir_handle)) 
{
	if ($file[0] != '.')
	{
		$dirpart = strpos($file,".");
		$dirpart = substr($file, 0,$dirpart);
		echo "$file move to dir $dirpart/$file\n";
		mkdir($dirpart);
		rename($file,"$dirpart/$file");
		$info = pathinfo($file);
	}
}

//closing the directory
closedir($dir_handle);

?> 
