#!/usr/bin/env sh
conf="$1";
tmp="tmp";
grep -v "^#" < $conf > $tmp;
while read LINE
do
	action=$(echo $LINE | cut -d: -f1);
	items=$(echo $LINE | cut -d: -f2);
	echo "$action:";
	IFS=",";
	for item in $items
	do
		echo $item;
		name=$(echo $item|cut -d" " -f1);
		mode=$(echo $item|cut -d" " -f2);
		echo "Create $name with mode $mode";
		if [ $action = "dir" ]
		then
			mkdir -p $name;
		else
			touch $name;
		fi
		chmod $mode $name;
	done
done < $tmp;