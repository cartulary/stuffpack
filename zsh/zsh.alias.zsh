alias -s txt=nano
alias -s cpp=nano
#alias -s awk=awk
#alias -s nawk=nawk
# cd to a file should take you to the dir that contains the file
# courtesy of Artur Penttinen <artur@xxxxxxxxxxx>
function cd () {
  if [[ -f $1 ]]; then
    builtin cd $1:h
  else
    builtin cd $1
  fi
}

#mkdir should cd as well
function mcd () {
	if [ $# -eq 1 ]
	then
		mkdir $1;
		cd $1;
	else
		mkdir $@;
	fi
}
setopt correct_all

alias man='nocorrect man'
alias mv='nocorrect mv'
alias cp='nocorrect cp'
alias touch='nocorrect touch'
alias ln='nocorrect ln'
alias mkdir='nocorrect mkdir'
alias firefox3="nocorrect firefox3 -no-remote";

alias cd\?="dirs";
alias back='cd "$OLDPWD";pwd'