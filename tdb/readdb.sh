#!/usr/bin/env sh
cat db | while read LINE;
do
	echo -n $LINE "-->" ;
	c=1;
	while [ $c -le 5 ];
	do
		result=$(echo "$LINE" | awk -F\| "{print \$$c}");
		echo -n $result;
		c=$(($c+1));
	done;
	item=$(echo "$LINE" | awk -F\| "{print \$1}");
	a=$(echo "$LINE" | awk -F\| "{print \$2}");
	b=$(echo "$LINE" | awk -F\| "{print \$3}");
	c=$(echo "$LINE" | awk -F\| "{print \$4}");
	echo -n $a $b $c;
	echo;
done;
