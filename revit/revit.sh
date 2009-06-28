#!/usr/bin/env sh
file="$1"
if [ -n $file ];
then
	echo "Reving $file";
else
	echo "Can't rev null" >&2;
	exit 1;
fi;

lastLineFile="";
lastline="";
while read line
do
	firstchar=$(echo $line|cut -c -1);
	firstthree=$(echo $line|cut -c -3);
	if [ ! "$firstthree" = "+++" -a ! "$firstthree" = "---" ];
	then
		case "$firstchar" in
			'+') echo $line|sed '1s/+/-/';;
			'-') echo $line|sed '1s/-/+/';;
			*) echo $line;;
		esac;
	else
		if [ -n "$lastLineFile" ]
		then
			lastLineFile="";
		else
			lastLineFile="true";
			echo $line;
			echo $lastline;
		fi
	fi;
	lastline=$line;
done < $file