#!/usr/bin/env perl
use strict;
use warnings;
my $debug = 0;
my @files = ();
foreach (@ARGV)
{
	if ($_ eq '-debug')
	{
		$debug = 1;
	}
	else
	{
		@files = (@files,$_);
	}
}

foreach (@files)
{
	if ( -e $_ )
	{
		print STDERR "fatal error: $_ exists\n"
	}
	else
	{
		if ($debug)
		{
			print "starting execution of $_ ...\n";
            print  "we are done\n";
		}
	}
}
