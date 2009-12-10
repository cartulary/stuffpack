#!/usr/bin/env sh
use_scm="";
opt_get_head="";
opt_export="";
opt_make_tar="";
while getopts ad:hetV option
do
	case "$option" in
		'a') opt_get_head="yes"; opt_export="yes"; opt_make_tar="yes";;
		'd') port="$OPTARG";;
		'h') opt_get_head="yes";; #get head
		'e') opt_export="yes";; #export files
		't') opt_make_tar="yes";; #tar files
		'V') echo "Tool maintained by Eitan Adler (EitanAdlerList@gmail.com). Please contact him with updates, changes, and fixes.";
			return 0;
	esac
done
echo "Dir: $port";

if [ -d "$port" ]
then
	cd "$port";
else
	echo "This port does not exist; fail!";
fi

do_get_head()
{
	svn_head=$(svn info $svn_url | grep "Revision" | cut -d' ' -f2);
	echo "SVN_REV=    $svn_rev" >$mk_masterdir/Makefile.svn_rev;
}

do_get_src()
{
	mkdir $mk_wrkdir;
	svn export -r $svn_rev $svn_url $mk_wrksrc;
}

do_make_tar()
{
	cd $mk_wrksrc;
	tar cvfy $mk_distdir/$mk_distname.tar.bz2 $mk_distname;
}

#can this be done faster? I don't want to have to run make 1000 times ;)
use_scm=$(make -V USE_SCM);
svn_rev=$(make -V SVN_REV);
svn_url=$(make -V SVN_URL);
mk_wrkdir=$(make -V WRKDIR);
mk_wrksrc=$(make -V WRKSRC);
mk_distdir=$(make -V DISTDIR);
mk_distname=$(make -V DISTNAME);
mk_masterdir=$(make -V MASTERDIR);

if [ "$use_scm" = "svn" ]
then
	echo "We don't yet handle non svn based projects. This is a future feature";
	return 1;
fi

if [ -n "$opt_get_head" ]
then
	do_get_head;
	echo "Head = $svn_head";
fi

if [ -n "$opt_export" ]
then
	do_get_src;
fi

if [ -n "$opt_make_tar" ]
then
	do_make_tar;
	echo "Not making tar";
fi

echo "Working with $svn_rev AND $svn_url";
