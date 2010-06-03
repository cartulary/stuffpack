#!/usr/bin/env bash
debug=false;
declare -a files;
while [ $# -gt 0 ];
do
	if [ $1 != "-debug" ];
	then
		files=("${files[@]}" "$1");
	else
		debug=true;
	fi;
	shift 1;
done;

for file in ${files[@]}
do
	if [ -e $file ];
	then
		echo fatal error: $file exists;
	else
		if ($debug);
		then
                  echo "starting execution of $file ...";
                  echo  "we are done";
		fi;
	fi;
done;
