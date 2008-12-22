#!/usr/local/bin/perl
$debug = false;
@files = ();
foreach $argnum (0 .. $#ARGV)
{
	if ($ARGV[$argnum]=='-debug')
	{
		$debug = true;
	}
	else
	{
		#perl does not add itself to the CLI arguments apperently
		@files = (@files,$ARGV[$argnum]);
	}
}
print "$debug\n";

foreach $argnum (0 .. @files)
{
	$file = @files[$argnum];
	if ( -e $file )
	{
		print STDERR "fatal error: $file exists\n"
	}
	else
	{
		if ($debug)
		{
			print "starting execution of $file ...\n";
                  print  "we are done\n";
		}
	}
}