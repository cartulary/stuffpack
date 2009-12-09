#!/usr/bin/env sh
use_scm="";
do_get_head="";
do_extract="";
do_make_tar="";
while getopts d:het option
do
	case "$option" in
		'd') port="$OPTARG";;
		'h') do_get_head="yes";; #get head
		'e') do_extract="yes";; #export files
		't') do_make_tar="yes";; #tar files
	esac
done
if [ -d "$port" ]
then
	cd "$port";
else
	echo "This port does not exist; fail!";
fi
which_scm()
{
}
pwd;
use_scm=$(make -V USE_SCM);
if [ "$use_scm" = "svn" ]
then
	echo "We don't yet handle non svn based projects. This is a future feature";
	return 1;
else
fi

return 0;
svn_rev=$(make -V SVN_REV);

port="$1"
echo "Dir: $port";
cd $port;
svn_url=$(make -V SVN_URL)
echo "Working with $svn_rev AND $svn_url";
svn_head=$(svn info $svn_url | grep "Revision" | cut -d' ' -f2)
echo "Head = $svn_head";

