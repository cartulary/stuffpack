#include <ctype.h>
#include <err.h>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/config/warning_disable.hpp>
#include <boost/config.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

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
	std::cout << "This is my ls\n";
	/* lets go through the arguments now */
	int c;
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
	if (file_name[0] != '.' || flagShowHidden)
	{
		std::cout << file_name;
	}
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
		if (bf::is_directory(*dir_itr))
		{
			std::cout << "/";
		}
		else if ( bf::is_regular_file(dir_itr->status()) )
		{
		}
		else
		{
			std::cout << "*";
		}
	}
	if (flagOneColOutput)
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


