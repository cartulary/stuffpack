__vcs_dir() {
	local vcs ref
	git_dir() {
  		git rev-parse HEAD 2>/dev/null|| return 1

 		ref=$(git name-rev --name-only HEAD)
		vcs="git"
	}
	hg_dir() {
		hg branch 1>/dev/null 2>/dev/null || return 1;

		ref="$(hg identify)";
		vcs="hg";
	}

	svn_dir() {
      	[ -d ".svn" ] || return 1

        	ref=$(svn info . | awk '/^Revision/ { sub("[^0-9]*","",$0); print $0}')
        	vcs="svn"
      }
  	svn_dir || hg_dir || git_dir ||  echo "";
	echo "${vcs:+[$vcs} ${vcs:+$ref]}"
}

#some settings
PS1_USER="%F{blue}%n";			#my username
if [ -n "$SSH_TTY" ]
then
	PS1_HOST="%B%F{blue}%m%b"
else
	PS1_HOST="%F{blue}%m";			#hostname
fi
PS1_ERR="%F{red}%(?..!%?!)";  		#return code of last command (if it was not 0)
PS1_WD="%F{magenta}%30<...<%~";	#current working directory limited to 30 chars
PS1_PROMPT="%#";					#EOF

function setCurrentPS1()
{
	PS1_VCS="%F{green}$(__vcs_dir)";	#info about the vcs
#	PS1_VCS="%(1v.%F{green}%1v%f.)";		
	PS1="[$PS1_USER@$PS1_HOST $PS1_WD $PS1_ERR%f]$PS1_PROMPT"
	RPROMPT="$PS1_VCS%f";

}

builtin cd $PWD
