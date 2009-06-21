#!/usr/bin/env sh

db="db";
search="";
look_for="";

usage()
{
	base=$(basename $0);
	echo "$base: metadata index for ports";
	echo;
	echo "Usage: $base [-aAdDfxV]";
	echo "-a adds a record";
	echo "-A adds a raw record";
	echo "-f changes the db filename";
	echo "-D remove raw string";
	echo "-d remove remove port";
	echo "-e remove all existing versions of a record and re-add it; instead of 'edit'";
	echo "-i for a specific item";
	echo "-s search for port";
	echo "-m machine readable";
}

add_raw_record()
{
	echo "$1" >> $db;
}

shortname_to_long()
{
	case "$1" in
		'ml-usr') echo -n "User Mailing List";;
		'ml-dev') echo -n "Development Mailing List";;
		'l') echo -n "License";;
		'ws') echo -n "Website ";;
		'forum') echo -n "Forums";;
		*) echo -n "[$1]";;
	esac;
}

add_new_record()
{
	echo "Lets talk about $1";
	item="--"
	val="--";
	rawstring="$1"
	items_to_ask="ml-usr ml-dev l ws forum";
	for item in $items_to_ask
	do
		read -p "$(shortname_to_long $item) ($item) - New value?" val;
		rawstring="$rawstring|$item=$val";
	done 
	read -p "Add $rawstring to db? [y/n]" reply;
	if [ "$reply" = "y" -o "$reply" = "Y" ];
	then
		add_raw_record $rawstring;
	fi
}

del_port()
{
	#think of a better random number thing
	#dd if=/dev/random of=/dev/stdout count=1 bs=1 conv=ascii
	echo $(grep -c "^$1|" $db);
	grep -v "^$1|" $db> "/tmp/$(basename $0)";
	mv "/tmp/$(basename $0)" $db;
}
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

disp_record()
{
	if [ -n "$machine" ];
	then
		echo -n "$1=";
	else
		echo -n " "$(shortname_to_long "$1");
		echo -n " is "
	fi;
	echo -n $(record_get_value "$2")" ";
}

op_db_record()
{
	recordname=$(record_get_item "$1");
	if [ -n "$look_for" ];
	then
		for item in "$look_for";
		do
			if [ "$item" = "$recordname" ];
			then
				disp_record "$recordname" "$1";
			fi
		done
	else
		disp_record "$recordname" "$1";
	fi;
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
			echo -n "Port $result:";
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
	grep "^$search" $1| while read LINE;
	do
		if [ -n "$LINE" ];
		then
			op_db_line $LINE;
		fi;
	done;
}

edit_record()
{
	how_many=$(del_port "$1");
	echo "(removed $how_many records)";
	add_new_record "$1";
}

while getopts a:A:D:d:e:i:f:ms:xV option
do
	case "$option" in
		'a') add_new_record "$OPTARG";
			exit 0;;
		'd') 	echo "removing port $1";
			how_many=$(del_port "$OPTARG");
			echo "(removed $how_many records)";
			exit 0;;
		'A') echo "Adding $OPTARG to $db";
			add_raw_record "$OPTARG";
			exit 0;;
		'e') edit_record $OPTARG;;
		'f') db="$OPTARG";;
		'i') look_for="$OPTARG";;
		's') search="$OPTARG";;
		'm') machine="Yes";;
		'x') set -x;;
		'V') echo "Version pre-alpha";
			exit 0;;
		'?') usage; exit 1;
	esac
done

if [ -f $db ];
then
	loop_through_db $db;
else
	echo "Are you insane!?";
fi;

