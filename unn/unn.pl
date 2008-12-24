#!/usr/local/bin/perl
$debug = false;
@files = ();
foreach $argnum (0 .. $#ARGV)
{
	if ($ARGV[$argnum] == '-debug')
	{
		$debug = true;
	}
	else
	{
		@files = (@files,$ARGV[$argnum]);
	}
}

foreach $argnum (0 .. @files -1)
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