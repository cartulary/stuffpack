#include <ctype.h>
#include <err.h>
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
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

int main(int argc, char *argv[])
{
	int c;
      while ((c = getopt (argc, argv, "ABCFGHILPRSTUWZabcdfghiklmnopqrstuwx1")) != -1)
	{
      	switch (c)
		{
			default:
				break;
		}

	}
	int i;
	for (i = 1; i < argc; ++i)
	{
		try
		{
			bf::path workingDir(argv[i]);
			std::cout <<  argv[i] << ": ";
			/* resolve the path */
			workingDir = bf::system_complete(workingDir);
  			if ( bf::exists( workingDir ) )
			{
				if ( bf::is_directory( workingDir ) )
				{
    					bf::directory_iterator end_iter;
					for (bf::directory_iterator dir_itr( workingDir ); dir_itr != end_iter; ++dir_itr)
					{
						if (bf::is_directory(*dir_itr))
						{
							std::cout << dir_itr->leaf() << "/" << std::endl;
							/* recurse this function if I'm supposed to */
						}
						else
						{
							std::cout << dir_itr->leaf();
							std::cout << std::endl;
						}
					}

					/* we have a directory */
					std::cout << "dir!" <<std::endl;
				}
				else
				{
					std::cout << "file!" <<std::endl;
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
}

void usage()
{
	std::cout << "usage: ls [-ABCFGHILPRSTUWZabcdfghiklmnopqrstuwx1] [file ...]" << std::endl;
//	exit(EX_USAGE);
}

