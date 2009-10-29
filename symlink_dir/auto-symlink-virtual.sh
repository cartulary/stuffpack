#!/usr/bin/env sh
#TODO -> release new version of port
##### Permission bug -> is the command not getting run?" ####
portdir="/usr/ports";
whereto=".";
dryrun="";
index="";
verbose="";
mapfile="";
mapfile_mode="ln -s";

usage()
{
	base=$(basename "$0");
	echo "$base: create symlinks for virtual ports"
	echo ""
	echo "Usage: $base [-hnv] [-i indexfile] [-p portsdir] [-w destdir]"
	echo ""
	echo " -h               show this usage"
	echo " -i indexfile     use this index file instead of traversing"
	echo "                  the ports tree"
	echo " -m mapfile		use mapfile to create new symlinks"
	echo " -M mapfile mode	what command to use to work with mapfiles";
	echo " -n               run through ports, but do not modify anything"
	echo " -p portsdir      use portsdir as the root of the ports tree"
	echo "			the default is /usr/ports/"
	echo " -v			be verbose and list all actions"
	echo " -V			display the current version."
	echo " -w destdir       use destdir as the base for resulting"
	echo "                  symlinks (default is current dir)"
}

while getopts dhi:Mm:np:Vvw: option
do    case "$option" in
	'd')  set -x;;
	'h')	usage;
		exit 0;;
	'm')	mapfile="$OPTARG";;
	'M')	mapfile_mode="$OPTARG";;
	'n')	dryrun="yes";;
	'i')	index=$OPTARG;;
	'p')  portdir=$OPTARG;;
	'v')	verbose="yes";;
	'w')	whereto=$OPTARG;;
	'V')	echo "Version 0.5";
		exit 0;;
	'?')  usage;
		exit 1;;
      esac
done

do_link_port()
{
	[ -n "$verbose" ] && echo "  " ln -s "$1" "$2";
	[ -z "$dryrun" ] && ln -s "$1" "$2";

}

do_make_cat_dir() 
{
	catname="$1"
	if [ ! -d "$whereto/$catname" ];
	then
		[ -n "$verbose" ] && echo "  " mkdir -p "$whereto/$catname";
		[ -z "$dryrun" ] && mkdir -p "$whereto/$catname";
	fi;
}

op_port()
{
	portpath=$1;
	item_cat=$2;
	portname=$3;
	portcat=$4;	
	do_make_cat_dir "$item_cat";
	if [ "$item_cat" = "$portcat" ]
	then dest="$whereto/$item_cat/$portname";
	else dest="$whereto/$item_cat/$portname-$portcat";
	fi;

	if [ ! -e $whereto/$item_cat/$portname -a ! -e $dest ];
	then
		do_link_port "$portpath" "$dest";
	fi;
}

transverse_sub_tree()
{
	portcat="$2";
	for portname in $(make -V SUBDIR -C $1/$portcat);
	do
		portpath="$1/$portcat/$portname";
		if [ -d "$1/$portcat/$portname" ];
		then
			echo -n "$portcat/$portname:";
			for item_cat in $(make -V CATEGORIES -C $1/$portcat/$portname);
			do
				[ -n "$verbose" ] && echo "-> Transversing $portcat/$item_cat";
				op_port $portpath $item_cat $portname $portcat;
			done;
			echo
		fi;
	done;
}

# this function transverses the main (/usr/ports/______) tree. It then calls
# another function to transverse the sub_tree
transverse_tree()
{
	for main_cat in $(make -V SUBDIR -C $1);
	do
		if [ -d "$1/$main_cat" ];
		then
			[ -n "$verbose" ] && echo "Transversing $main_cat";
			transverse_sub_tree "$1" "$main_cat"
		fi;
	done;
}

transverse_index()
{
	cat "$1/$index" | while read LINE;
	do
		portpath=$(echo "$LINE" | awk -F\| '{print $2}')
		portcats=$(echo "$LINE" | awk -F\| '{print $7}')
		portname=$(basename "$portpath")
		portcat=$(basename $(dirname "$portpath"))
		echo "$portname: $portcats"
		for item_cat in $portcats;
		do
			op_port $portpath $item_cat $portname $portcat;
		done
	done
}

do_map()
{
	oldport="$1";
	newport=$(basename $2);
	newportdir=$(dirname $2);
	if [ ! -d "$whereto/$newportdir" ]
	then
		[ -n "$verbose" ] && echo "mkdir -p \"$newport\" \"$whereto/$newportdir\"";
		[ -z "$dryrun" ] && mkdir -p "$newport" "$whereto/$newportdir";
	fi

	[ -n "$verbose" ] && echo "$mapfile_mode \"$portdir/$oldport\" \"$whereto/$newportdir/$newport\"";
	[ -z "$dryrun" ] && $mapfile_mode "$portdir/$oldport" "$whereto/$newportdir/$newport";
}

do_mapfile()
{
	mapfile="$1";
	while read LINE
	do
		oldport=$(echo $LINE|cut -d " " -f 1);
		newport=$(echo $LINE|cut -d " " -f 2);
		do_map "$oldport" "$newport"
	done < "$mapfile";
}

if [ ! -d "$portdir" ];
then
	echo "Complete failure";
	exit 1;
fi;

if [ -n "$mapfile" ]
then
	if [ ! -e "$mapfile" ]
	then
		echo "Mapfile does not exist";
		exit 1;
	fi
	do_mapfile "$mapfile";
	exit 0;
fi

if [ -z "$index" ];
then
	if [ ! -e "$portdir/Makefile" ];
	then
		echo "No Makefile";
		exit 1;
	fi;
	transverse_tree "$portdir";
else
	# test that index exists and that the size is greater than 0.
	if [ ! -s "$portdir/$index" ];
	then
		echo "Invalid Index";
		exit 1;
	fi;
	transverse_index "$portdir";
fi;

return 0;

#Copyright 2009  Eitan Adler <EitanAdlerList@gmail.com>

#Redistribution and use in source and binary forms, with or without
#modification, are permitted provided that the following conditions
#are met:

#1. Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
#2. Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.

#THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
#IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
#OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
#IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
#INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
#NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
#THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



#TODO
# add even more failure and sanity testing
# add comments explaining what is going on
# add "mapping" option to allow you add your own categories?
# add the ability to change the mask used to name the ports w/i each virtual category.
