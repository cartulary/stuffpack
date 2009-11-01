#!/usr/bin/env sh
cd new
while read LINE
do
	portpath=$(echo "$LINE" | awk -F\| '{print $2}');
	portname=$(basename "$portpath");
	portcat=$(basename $(dirname "$portpath"))
	it=$(echo "$portname [$portpath]"|grep -E "(i18n)|(l10n)");
	if [ -n "$it" ];
	then
		echo $it;
		if [ -d $portpath ];
		then
			echo old: $(make -C $portpath -V CATEGORIES);
			linenum=$(cat $portpath/Makefile | grep -n CATEGORIES);
			linenum=$(echo $linenum|awk -F: '{print $1}');
			echo $linenum;
			cmd=$linenum"s/\$/ i18n/"
			echo $(cat $portpath/Makefile|sed "$cmd"|awk "NR==$linenum{print \$0;}");
			$(sed -ibak "$cmd" ./$portcat/$portname/Makefile);
		fi;
	fi;
done < INDEX-8
