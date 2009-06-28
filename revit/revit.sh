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
IFS="\n";
while read -r line
do
	firstchar=$(echo "$line"|cut -c -1);
	firstthree=$(echo "$line"|cut -c -3);
	if [ ! "$firstthree" = "+++" -a ! "$firstthree" = "---" ];
	then
		line=$(switch_first_char "$firstchar" "$line");
#		if [ ! "$firstchar" = "+" -a ! "$firstchar" = "-" -a ! "$firstchar" = "@" ]
#		then
#			echo -n " ";
#		fi
		if [ "$firstchar" = "@" ]
		then
			part1=$(echo $line|cut -d' ' -f'2');
			part1A=$(echo $part1|cut -d',' -f'1');
			part1B=$(echo $part1|cut -d',' -f'2');
			part2=$(echo $line|cut -d' ' -f'3');
			part2A=$(echo $part2|cut -d',' -f'1');
			part2B=$(echo $part2|cut -d',' -f'2');
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
done < $file

#bugs: when no newline unable to deal with the \
#bugs: svn diff equal line filename seperator won't work
#bugs: never tested with subdirectory; creating new files; or anything like that