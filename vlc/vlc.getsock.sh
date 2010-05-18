#!/usr/bin/env sh
optdir="/home/eitan/.vlc_extra";
current_sock="";
. "$optdir/socket_name";
#echo current socket is $current_sock;

isrunning()
{
	if [ -n "$current_sock" -a -e "$current_sock" ]
	then
		return $(true);
	else
		return $(false);
	fi
}
