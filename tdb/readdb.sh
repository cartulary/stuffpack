#!/usr/bin/env sh

db=db

usage()
{
	base=$(basename $0);
	echo "$base: metadata index for ports";
	echo;
	echo "Usage: $base [-fxV]";
	echo
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

op_db_line()
{
}

loop_through_db()
{
	cat $db | while read LINE;
	do
		if [ -n "$LINE" ];
		then
			echo -n "$LINE" "-->" ;
			c=1;
			max_col=$(echo $LINE|sed "s/[^|]//g"|wc -c);
			while [ $c -le $max_col ];
			do
				result=$(echo "$LINE" | awk -F\| "{print \$$c}");
				item=$(echo $result | awk -F= "{print $1}");
				value=$(echo $result | awk -F= "{print $1}");
				echo -n " $item is $value";
				c=$(($c+1));
			done;
	echo;
		fi;
	done;
}

loop_through_db;