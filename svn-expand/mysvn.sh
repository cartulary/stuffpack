#!/usr/bin/env sh

regex="^(add|commit|import|(merge)?info|prop(list|del|edit|get|set)|blame|copy|sw(itch)?|mkdir|(un)?lock|cat|delete|list|move|resolve|up(date)?|changelist|checkout|c(l|o|i|p)|di|p(d|e|g|l|s)|st|cleanup|diff|export|help|lock|merge|resolved|revert|stat(us)?|praise|annotate|ann|cl|cp|del|ls|h|\?)$";
realsvn=$(printf "%s" "$1" |grep -Ec "$regex")
#echo $realsvn;
#return 0;

if [ $realsvn -eq 1 ]
then
	\svn $@;
	return $?;
fi
case "$1" in
	"ohelp")
		echo "no help currently available";;
	"grep")
		#move everthing over to get rid of "svn" and then ask grep to help us
		shift 1;
		grep --exclude "*svn*" ;;
	*)
		#since we have an invalid command lets call the real svn -> get a usage message -> then print our extension
		\svn $@;
		echo "--> Also valid: ohelp";;
esac

