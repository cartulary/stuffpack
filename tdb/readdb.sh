#!/usr/bin/env sh
cat db | while read LINE;
do
	if [ -n "$LINE" ];
	then
		echo -n "$LINE" "-->" ;
		c=1;
		while [ $c -le 5 ];
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
