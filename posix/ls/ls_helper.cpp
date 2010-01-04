#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/config/warning_disable.hpp>
#include <boost/config.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

namespace bf = boost::filesystem;

char get_post_symbol(bf::directory_iterator dir_itr, struct stat buf)
{
	if (bf::is_directory(*dir_itr))
	{
		return '/';
	}
	else if ( bf::is_regular_file( dir_itr->status() ))
	{
		return 0;
	}
	else if ( bf::is_symlink( dir_itr->status() ))
	{
		return '@';
	}
	else if (false) //is_executible
	{
		return '*';
	}
	else if (S_ISFIFO(buf.st_mode))
	{
		return '|';
	}
	else if (S_ISSOCK(buf.st_mode))
	{
		return '=';
	}
	else if (S_ISWHT(buf.st_mode))
	{
		return '%';
	}
	else
	{
		return '&';
	}
}
