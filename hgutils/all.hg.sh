#!/usr/bin/env sh
. ~/.conf/zsh/eval_spin.func
for remote in $(<.remotes cat)
do
	echo "=== $remote ===";
	spin gtimeout 20 hg "$@" "$remote"; 
	if [ $? -eq 124 ]
	then	
		echo "command timed out" > /dev/stderr
	fi
done
