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
		'-') echo "$2"|sed '1s/-/+/';;
	esac;
}

switchLastLine="";
lastline="";
IFS="\n";
while read -r line
do
	firstchar="$(echo "$line"|cut -c -1)";
	firstthree="$(echo "$line"|cut -c -3)";
	if [ ! "$firstthree" = "+++" -a ! "$firstthree" = "---" ];
	then
		if [ "$firstchar" = "+" -o "$firstchar" = "-" ]
		then
			line=$(switch_first_char "$firstchar" "$line");
		fi;
		if [ "$firstchar" = "@" ]
		then
			part1=$(echo "$line"|cut -d' ' -f'2');
			part1A=$(echo "$part1"|cut -d',' -f'1');
			part1B=$(echo $part1|cut -d',' -f'2');
			part2=$(echo "$line"|cut -d' ' -f'3');
			part2A=$(echo $part2|cut -d',' -f'1');
			part2B=$(echo $part2|cut -d',' -f'2');
			# Lets move some stuff around - I hope this works - I don't understand patch well enouph to know that this will work every time.
			line="@@ $part1A,$part2B $part2A,$part1B @@";
		fi;
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
done < "$file"

#bugs: never tested with subdirectory; creating new files; or anything like that
#todo: make the diff -q >> many patches script as well