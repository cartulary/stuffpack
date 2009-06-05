#!/usr/bin/env sh
portdir="/usr/ports"
whereto="."
dryrun=""
index=""
while getopts di:np:w: option
do    case "$option" in
      'd')  set -x;;
	'n')	dryrun="yes";;
	'i')	index=$OPTARG;;
      'p')  portdir=$OPTARG;;
	'w')	whereto=$OPTARG;;
      '?')  echo "Usage: $0 [-d] [-pPortdir] -wWhereTo" >&2;
            exit 1;;
      esac
done

if [ ! -d $portdir ];
then
	echo "Complete failure";
	exit 1;
else
	if [ ! -e $portdir/Makefile ];
	then
		echo "No Makefile";
		exit 1;
	fi;
fi;

if [ -z "$index" ];
then

for main_cat in $(make -V SUBDIR -C $portdir);
do
	if [ -d $portdir/$main_cat ];
	then
		for port in $(make -V SUBDIR -C $portdir/$main_cat);
		do
			if [ -d $portdir/$main_cat/$port ];
			then
				echo -n "$main_cat/$port:";
				for item_cat in $(make -V CATEGORIES -C $portdir/$main_cat/$port);
				do
					echo -n "$item_cat "
					if [ -z "$dryrun" -a ! -d $whereto/$item_cat ];
					then
						mkdir $whereto/$item_cat;
					fi;
					if [ -z "$dryrun" -o ! -e $whereto/$item_cat/$port ];
					then
						if [ -z "$dryrun" ];
						then
							echo "ln -s $portdir/$main_cat/$port  $whereto/$item_cat/$port-$main_cat"
						else
							#this won't create the main ports because we check to see if the main port one exits BUT
							#we add the main cat to the filename in case of name conflicts
							ln -s $portdir/$main_cat/$port  $whereto/$item_cat/$port-$main_cat
						fi;
					fi;
				done;
				echo
			fi;
		done;
		echo $main_cat
	fi;
done;

else
	cat $portdir/$index | while read LINE;
	do
		portpath=$(echo "$LINE" | awk -F\| '{print $2}')
		portcats=$(echo "$LINE" | awk -F\| '{print $7}')
		portname=$(basename $portpath)
		portcat=$(basename $(dirname $portpath))
		echo "$portname: $portcats"
		for cat in $portcats;
		do
			item_cat=$cat
			if [ ! -d $whereto/$item_cat ];
			then
				[ -n "$verbose" ] && echo "  " mkdir $whereto/$cat;
				[ -z "$dryrun" ] && mkdir $whereto/$cat;
   			fi;
			if [ ! -e $whereto/$cat/$portname ];
 			then
				[ -n "$verbose" ] && echo "  " ln -s \
					"$portpath" "$whereto/$cat/$portname-$portcat";
				[ -z "$dryrun" ] && ln -s \
					"$portpath" "$whereto/$cat/$portname-$portcat";
			fi;
		done
	done
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