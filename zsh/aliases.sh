alias mv="mv -i";
alias cp="cp -i";
if [ ls -T >/dev/null 2>&1 ]
then
	alias ls="ls -FG";
fi
if [ $(uname -s ) = "FreeBSD" ]
then
	alias rm="rm -I";
	alias less="less -R";
fi
alias cEterm="\Eterm -C -T 'Console Eterm' -f'red'";
#alias nvlc="nvlc --volume 1024";
#alias vlc="vlc_create_sock";
alias python2="python -tt3";
alias python="python3.1"
alias noflash="pkill -3 -l npviewer.bin";
alias noflash_9="noflash|sed "s/3/9/"|sh -x 2>&1|sed 's/\+ //'";
alias switch-background="pkill idesk && idesk &";
alias youtube-dl="youtube-dl -t";
alias startx="ssh-agent startx -audit 4 -nolisten tcp";
alias sgrep='grep --exclude "*svn*" -I';
alias srcloc="whereis -qs";
alias portmaster="portmaster -m'-DNO_DEPENDS'";
alias su="su -l"
alias pc="proxychains";
alias shareThisDir="python3 -m http.server 8000";

alias p="pushd"
alias b="popd"

