#!/usr/bin/env sh
cmd_to_tell="";
x_mode="";
optdir="/home/eitan/.vlc_extra";
. "$optdir/socket_name";
while getopts c:o:x option
	do case "$option" in
	'c') cmd_to_tell="$OPTARG";;
	'o') optdir="$OPTARG";;
	'x') x_mode="on";;
	esac
done

if [ -z "$cmd_to_tell" ]
then
	if [ -n "$x_mode" ]
	then
      	Xdialog --icon ~/bin/icons/warning.xpm --infobox "Missing a cmd!" 0 0 2000;
	else
		echo "Your missing a command..." >/dev/stderr;
	fi
	return 1;
	
fi
## if no opts give entire line not just cmd_to_tell

if [ -e "$current_sock" ]
then
	echo "$cmd_to_tell"|nc -U $current_sock
	if [ -n "$x_mode" ]
	then
		Xdialog --title "VLC Remote control" --backtitle "I told vlc to " --no-buttons --icon ~/bin/icons/media-cdrom.xpm --infobox "$cmd_to_tell" 0 0 3000
	fi
else
	if [ -n "$x_mode" ]
	then
      	Xdialog --icon ~/bin/icons/warning.xpm --infobox "VLC not running!" 0 0 2000;
	fi
	return 1;
fi
