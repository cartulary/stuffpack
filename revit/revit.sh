#!/usr/bin/env sh
file="$1"
if [ ! -n $file ];
then
	echo "Can't rev null" >&2;
	exit 1;
fi;

switch_first_char()
{
	case "$1" in
		'+') echo "$2"|sed '1s/+/-/';;
		'-') echo $2|sed '1s/-/+/';;
		*) echo $2;;
	esac;
}

switchLastLine="";
lastline="";
while read line
do
	firstchar=$(echo "$line"|cut -c -1);
	firstthree=$(echo "$line"|cut -c -3);
	if [ ! "$firstthree" = "+++" -a ! "$firstthree" = "---" ];
	then
		line=$(switch_first_char "$firstchar" "$line");
		if [ ! "$firstchar" = "+" -a ! "$firstchar" = "-" ]
		then
			echo -n " ";
		fi
		echo "$line";
	else
		if [ -n "$switchLastLine" ]
		then
			switchLastLine="";
			echo "$line";
			echo "$lastline";
		else
			switchLastLine="true";
		fi
	fi;
	lastline="$line";
done < $file