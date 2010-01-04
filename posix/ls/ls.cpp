#include <ctype.h>
#include <err.h>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
/* for the non-standard user_from_uid and group_from_gid functions */
#include <pwd.h>
#include <grp.h>
#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/config/warning_disable.hpp>
#include <boost/config.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include "ls_helper.cpp"
void usage();

namespace bf = boost::filesystem;

/*  various options */
/* showDotLinks - show . and ..
  showHidden - show hidden files (. files on unix)
*/
bool flagShowHidden = false, flagShowDotLinks = false;
bool flagPrintUnprintableChars = false, flagUseCEscapeCodes = false;
/* multi col should be false when piping */
bool flagMultiColOutput = true, flagOneColOutput = false, flagSortAcross = false;
/* showPathSymbol == -P			showDirSymbol == -F */
bool flagShowPathSymbol = false, flagShowDirSymbol = false;
bool flagColorize = false;
bool flagFollowSymLinks = true, flagFollowArgumentSymLinks = false;
/* never be recursive is for the the -d option */
bool flagBeRecursive = false, flagNeverBeRecursive = false;
/* don't sort should be false - but I don't feel like sorting yet */
bool flagSortBySize = false, flagSortTimeCreated = false, flagSortByLastChanged = false, flagDontSort = true, flagReverseSort = false, flagSortTimeModified, flagSortLastAccess;
bool flagShowCompleteTimeInfo = false;
bool flagDisplayWhiteouts = false;
bool flagDisplayMacLabel = false;
bool flagFileSizeHumanReadable = false;
bool flagDisplayFileInodeNum = false, flagDisplayNumBlocks = false;
bool flag1024BlockSize = false;
bool flagDisplayLong = false, flagShowFileFlags = false;
bool flagStreamOutput = false;
bool flagDisplayUidAsNumber = false;
bool flagDisplayNonGraphicAsQuestionMark = false;
bool flagRawNonGraphic = true;

void printFile(bf::directory_iterator dir_itr);
void opArg(char* arg);

int main(int argc, char *argv[])
{
	/* lets go through the arguments now */
	int c;
	if (getuid() == static_cast<uid_t>(0))
	{
		flagShowHidden = true;
	}
	while ((c = getopt (argc, argv, "ABCFGHILPRSTUWZabcdfghiklmnopqrstuwx1")) != -1)
	{
		switch (c)
		{
			case 'A':
				flagShowHidden = true;
				flagShowDotLinks = false;
				break;
			case 'F':
				flagShowPathSymbol = true;
				break;
			case 'I':
				flagShowHidden = false;
				break;
			case 'a':
				flagShowHidden = true;
				flagShowDotLinks = true;
				break;
			case 'i':
				flagDisplayFileInodeNum = true;
				break;
			case 'l':
				flagDisplayLong = true;
				break;
			case 'n':
				flagDisplayUidAsNumber = true;
				break;
			case 'p':
				flagShowDirSymbol = true;
				break;
			case '1':
				flagOneColOutput = true;
				break;
			default:
				break;
		}
	}

	if (argc > optind)
	{
		int i;
		for (i = optind; i < argc; ++i)
		{
			opArg(argv[i]);
		}
	}
	else
	{
		opArg(".");
	}
	std::cout << std::endl;
}

void usage()
{
	std::cout << "usage: ls [-ABCFGHILPRSTUWZabcdfghiklmnopqrstuwx1] [file ...]" << std::endl;
//	exit(EX_USAGE);
}

void printFile(bf::directory_iterator dir_itr)
{
	std::string file_name = dir_itr->path().filename();


	struct stat buf;
	int status;
	errno=0;
	status = stat(file_name.c_str(), &buf);
	if (errno!=0)
	{
		//I think we have some kind of problem - so lets get out of here for now. I will have to deal with this case later
		return;
		std::cerr << "errno != 0 on stat\n";
	}
	if (flagDisplayLong)
	{
		if (flagDisplayUidAsNumber)
		{
			std::cout << buf.st_mode << ' '<< buf.st_uid<< ' ' << buf.st_gid << ' ';
		}
		else
		{
			// not standard - see if there is a better way of doing this
			std::cout << buf.st_mode << ' '<< user_from_uid(buf.st_uid,0)<< ' ' << group_from_gid(buf.st_gid,0) << ' ';
		}
	}
	if (flagDisplayFileInodeNum)
	{
		std::cout << ' '<<buf.st_ino << ' ';
	}
	if (flagDisplayLong)
	{
		std::cout << buf.st_size;
	}
	if (file_name[0] == '.' && !flagShowHidden)
	{
		// we are a hidden file so lets get outa here
		return;
	}
	std::cout << file_name;

	/* -p stuff */
	if (flagShowDirSymbol)
	{
		if (bf::is_directory(*dir_itr))
		{
			std::cout << "/";
		}
	}
	/* -F stuff */
	if (flagShowPathSymbol)
	{
		char post_symbol = get_post_symbol(dir_itr, buf);
		std::cout << post_symbol;
	}
	if (flagOneColOutput || flagDisplayLong)
	{
		std::cout << std::endl;
	}
	else
	{
		std::cout << " ";
	}
}

void opArg(char* arg)
{
	try
	{
		bf::path workingDir(arg);
		/* resolve the path */
		workingDir = bf::system_complete(workingDir);
  		if ( bf::exists( workingDir ) )
		{
			if ( bf::is_directory( workingDir ) )
			{
    			bf::directory_iterator end_iter;
				for (bf::directory_iterator dir_itr( workingDir ); dir_itr != end_iter; ++dir_itr)
				{
					printFile(dir_itr);
				}
			}
			else
			{
				/* we have a file or something special - will deal with this later */
			}
		}
		else
		{
			std::cout << "doesn't exist" <<std::endl;
		}
	}
	catch (bf::filesystem_error e)
	{
		std::cout << "Exception occured!" << e.what() << std::endl;
	}
}


