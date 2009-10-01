#!/usr/bin/env sh
usage()
{
	base=$(basename $0);
	echo "$base: watch a command run multiple times";
	echo "";
	echo "Usage: $base [-dV] [-s seconds] -c cmd";
	echo "";
	echo "-c		What command to run";
	echo "-d		Debugging mode";
	echo "-V		Print version information then exit";
	echo "-s		Time to delay between command runs";	
	echo "";
}
#set the default values
seconds="1";
cmd="";

#lets set the variables here
#Why can't we get cmd to not require -c ??
while getopts c:ds:V option
do	case "$option" in
	'c') cmd="$OPTARG" ;;
	'd') set -x;;
	's') seconds="$OPTARG";;
	'V') echo "Version 0.1";
		exit 0;;
	'?') usage;
		exit 1;;
	esac
done

# lets make sure we have a command to run
if [ -z "$cmd" ]
then
	# we don't so print usage and exit
	usage;
	exit 1;
fi;

#lets run the command; sleep; run the command; sleep etc
while	[ 1 ]
do
	$cmd;
	sleep $seconds;
done

#feature request: make the number of the command is run choosable
#feature request: verify this implentation against the Linux version
#???		    : Is signal proccessing correct?