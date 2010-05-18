#!/usr/bin/env sh
optdir="/home/eitan/.vlc_extra";
. "$optdir/socket_name";
#echo current socket is $current_sock;

isrunning()
{
	if [ -e "$current_sock" ]
	then
		return $(true);
	else
		return $(false);
	fi
}
