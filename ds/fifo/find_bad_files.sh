#!/usr/bin/env bash
#This will be a shell script to find bad files
# 1) headers without a header guard
# 2) files that don't end in a newline
LC_COLLATE=C;
for file in *.h
do
	header=$(echo $file| sed "s/\./_/" | tr '[:lower:]' '[:upper:]');
	head -1 $file| grep --label=$file:ndef -L "\#ifndef $header";
	head -2 $file| tail -1| grep --label=$file:define -L "\#define $header";
	tail -1 $file| grep --label=$file:endif -L "\#endif";
done

for file in *.{cpp,h}
do
	if [[ $(tail -c 1 "$file") -ne "" ]]
	then
		echo "$file fails with newline";
	fi
done


echo "";
