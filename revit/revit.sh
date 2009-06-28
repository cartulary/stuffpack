#!/usr/bin/env sh
file="$1"
if [ ! -n $file ];
then
	echo "Can't rev null" >&2;
	exit 1;
fi;

switchLastLine="";
lastline="";
while read line
do
	firstchar=$(echo "$line"|cut -c -1);
	firstthree=$(echo "$line"|cut -c -3);
	if [ ! "$firstthree" = "+++" -a ! "$firstthree" = "---" ];
	then
		if [ "$firstchar" = "+" -o "$firstchar" = "-" ]
		then
			if [ -n "$switchLastLine" ]
			then
				switchLastLine="";
				echo $line;
				echo $lastline;
			else
				switchLastLine="true";
			fi
		else
			echo $line;
		fi
	else
		if [ -n "$switchLastLine" ]
		then
			switchLastLine="";
			echo $line;
			echo $lastline;
		else
			switchLastLine="true";
		fi
	fi;
	lastline="$line";
done < $file