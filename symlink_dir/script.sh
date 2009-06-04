#!/usr/bin/env bash
cd /usr/ports/
for main_cat in $(make -V SUBDIR);
do
	if [ -d $main_cat ];
	then
		for port in $(make -V SUBDIR -C $main_cat);
		do
			echo "$main_cat/$port"
		done;
		echo $main_cat
	fi;
done;