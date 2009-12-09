#!/usr/bin/env sh
portdir="/usr/ports";
buildfirst="";
db="confdb";
usage()
{
	base=$(basename $0);
	echo "$base: looks for lack of parity of ports conflicts";
	echo "";
	echo "Usage: $base [-b] [-dh] [ -c confdb ][ -p portsdir ]";
	echo "";
	echo " -b 			build db before testing parity";
	echo " -c			use this file as the conf db";
	echo " -h			shows this usage";
	echo " -p portsdir		use portsdir as root of ports tree"
	echo "			/usr/ports is default";
	echo " -d			Enable debugging output";
	echo " -V			displays version number then exits";
	echo "";
	echo "Please send bug reports and other enhancments to EitanAdlerList@gmail.com";
}

while getopts bc:dhp:V option
do case "$option" in
	'b')	buildfirst="YES";;
	'c')	db="$OPTARG";;
	'd')	set -x;;
	'h')	usage;
		exit 0;;
	'p')	portsdir="$OPTARG";;
	'V')	echo "Version 0.1";
		exit 0;;
	'?')	usage;
		exit 64;; #(64 == EX_USAGE)
	esac
done
build_db()
{
	# Empty the database file
	:>"$db";
	for main_cat in $(make -V SUBDIR -C $portdir)
	do
		for portname in $(make -V SUBDIR -C $portdir/$main_cat)
		do
			conflicts=$(make -V CONFLICTS -C $portdir/$main_cat/$portname);
			if [ ! -z "$conflicts" ]
			then
				pname=$(make -V PKGNAME -C $portdir/$main_cat/$portname);
				for conflict in $conflicts
				do
					echo "$pname: $conflict"|tee -a "$db";
				done			
			fi
		done
	done
}

paritycheck()
{
	# cut -f 1 == pkgname
	# cur -f 2 == conflict name
	while read line
	do
		port=$(echo $line|cut -d ":" -f 1);
		conflict=$(echo $line|cut -d ":" -f 2);
		echo "looking in $port for $conflict";
		num_match=$(cat "$db"|cut -d ":" -f 1|grep -Ec $conflict);
		echo $num_match;
		if [ $num_match -eq 0 ]
		then
			echo "$port fails with $conflict" >/dev/stderr;
		fi
		echo "================";
	done < "$db"
}

if [ ! -z "$buildfirst" ]
then
	build_db;
fi
paritycheck;