#!/usr/bin/env bash
portdir="/usr/ports"
for main_cat in $(make -V SUBDIR -C $portdir);
do
	if [ -d $portdir/$main_cat ];
	then
		for port in $(make -V SUBDIR -C $portdir/$main_cat);
		do
			echo -n "$main_cat/$port:";
			for item_cat in $(make -V CATEGORIES -C $portdir/$main_cat/$port);
			do
				echo -n "$item_cat "
				if [ ! -d $item_cat ];
				then
					mkdir $item_cat;
				fi;
				if [ ! -e $item_cat/$port ];
				then
					ln -s $portdir/$port  $item_cat/$port
				else
					echo "symlink already exists - working on this failure case";
				fi;
			done;
			echo
		done;
		echo $main_cat
	fi;
done;