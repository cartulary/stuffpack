#!/usr/bin/env sh
portdir="/usr/ports"
whereto="."
dryrun=""
index=""
verbose=""
while getopts di:np:vw: option
do    case "$option" in
      'd')  set -x;;
	'n')	dryrun="yes";;
	'i')	index=$OPTARG;;
      'p')  portdir=$OPTARG;;
	'v')	verbose="yes";;
	'w')	whereto=$OPTARG;;
      '?')  echo "Usage: $0 [-d] [-pPortdir] -wWhereTo" >&2;
            exit 1;;
      esac
done

do_link_port()
{
	[ -n "$verbose" ] && echo "  " ln -s "$1" "$2";
	[ -z "$dryrun" ] && ln -s $1 $2;

}

do_make_cat_dir() 
{
	if [ ! -d $whereto/$1 ];
	then
		[ -n "$verbose" ] && echo "  " mkdir $whereto/$1;
		[ -z "$dryrun" ] && mkdir $whereto/$1;
	fi;
}

transverse_sub_tree()
{
	for port in $(make -V SUBDIR -C $1/$2);
	do
		if [ -d $1/$2/$port ];
		then
			echo -n "$2/$port:";
			for item_cat in $(make -V CATEGORIES -C $1/$2/$port);
			do
				echo "$item_cat "
				do_make_cat_dir $item_cat;
				if [ ! -e $whereto/$item_cat/$port -a ! -e $whereto/$item_cat/$port-$2 ];
				then
					do_link_port "$1/$2/$port" "$whereto/$item_cat/$port-$2";
				fi;
			done;
			echo
		fi;
	done;
}


transverse_tree()
{
	for main_cat in $(make -V SUBDIR -C $1);
	do
		if [ -d $1/$main_cat ];
		then
			[ -n "$verbose" ] && echo "Transversing $main_cat";
			transverse_sub_tree $1 $main_cat
		fi;
	done;
}

transverse_index()
{
	cat $1/$index | while read LINE;
	do
		portpath=$(echo "$LINE" | awk -F\| '{print $2}')
		portcats=$(echo "$LINE" | awk -F\| '{print $7}')
		portname=$(basename $portpath)
		portcat=$(basename $(dirname $portpath))
		echo "$portname: $portcats"
		for item_cat in $portcats;
		do
			do_make_cat_dir $item_cat;
			if [ ! -e $whereto/$item_cat/$portname -a ! -e $whereto/$item_cat/$portname-$portcat ];
 			then
				do_link_port "$portpath" "$whereto/$item_cat/$portname-$portcat";
			fi;
		done
	done
}

if [ ! -d $portdir ];
then
	echo "Complete failure";
	exit 1;
fi;

if [ -z "$index" ];
then
	if [ ! -e $portdir/Makefile ];
	then
		echo "No Makefile";
		exit 1;
	fi;
	transverse_tree $portdir;
else
	if [ ! -e $portdir/$index ];
	then
		echo "No Index";
		exit 1;
	fi;
	transverse_index $portdir;
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
# try and merge index and non-index functionality.
# add failure and sanity testing