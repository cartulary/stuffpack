#!/usr/bin/env sh

db=db

usage()
{
	base=$(basename $0);
	echo "$base: metadata index for ports";
	echo;
	echo "Usage: $base [-fxV]";
	echo "-a adds a record";
	echo "-A adds a raw record";
	echo "-f changes the db filename";
}

while getopts f:xV option
do
	case "$option" in
		'f') db=$OPTARG;;
		'x') set -x;;
		'V') echo "Version pre-alpha";
			exit 0;;
		'?') usage; exit 1;
	esac
done

# record = one name-pair value; line = one entry in the DB
#bug with \| -> work on this later; bug with \= -> work on this later.
record_get_item()
{
	echo "$1" | awk -F= '{print $1}';
}

record_get_value()
{
	echo "$1" | awk -F= '{print $2}';
}

op_db_record()
{
	echo -n " "$(record_get_item "$1");
	echo -n " is "
	echo -n $(record_get_value "$1")" ";
}

op_db_line()
{
	#echo -n "$LINE" "-->" ;
	c=1;
	max_col=$(echo "$LINE"|sed "s/[^|]//g"|wc -c);
	while [ $c -le $max_col ];
	do
		result=$(echo "$LINE" | awk -F\| "{print \$$c}");
		if [ $c = 1 ];
		then
			echo -n "Port $result";
		else
			op_db_record "$result";
			echo -n ";"
		fi;
		c=$(($c+1));
	done;
	echo;
}

loop_through_db()
{
	cat $db | while read LINE;
	do
		if [ -n "$LINE" ];
		then
			op_db_line $LINE;
		fi;
	done;
}

loop_through_db;