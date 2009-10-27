#!/usr/bin/env sh
usage()
{
	base=$(basename $0);
	echo "$base: watch a command run multiple times";
	echo "";
	echo "Usage: $base [-dV] [ -n times ] [-s seconds] -c cmd";
	echo "";
	echo "-c		What command to run";
	echo "-d		Debugging mode";
	echo "-n		Run the command N times";
	echo "-V		Print version information then exit";
	echo "-s		Time to delay between command runs";	
	echo "";
}
#set the default values
seconds="1";
cmd="";
# by default we go forever; but we use -lt later on so we need to set this
ntimes=1;
# we use this instead of checking ntimes...
forever="YES";

#lets set the variables here
#Why can't we get cmd to not require -c ??
while getopts c:dn:s:V option
do	case "$option" in
	'c') cmd="$OPTARG" ;;
	'd') set -x;;
	'n')	ntimes=$OPTARG;
		forever="";;
	's') seconds="$OPTARG";;
	'V') echo "Version 0.2";
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
count=0;
while	[ $count -lt $ntimes ]
do
	$cmd;
	sleep $seconds;

	# we only increment counter if we want to stop...
	if [ -z $forever ]
	then
		count=$(($count + 1));
	fi
done

#feature request: verify this implentation against the Linux version
#???		    : Is signal proccessing correct?