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

void usage();

namespace bf = boost::filesystem;

int main(int argc, char *argv[])
{
	int c;
	int toReturn = 0;
      while ((c = getopt (argc, argv, "RHLPfinalpv")) != -1)
	{
      	switch (c)
		{
			case 'a':
				break;
			default:
				break;
		}

	}

	if (argc > 1)
	{
		std::string finalFile =  argv[argc - 1] ;
		std::cout << "Final file == " << finalFile << std::endl;
		bf::path finalPath(finalFile);
		bool cpDirMode = false;
		if( bf::exists(finalPath))
		{
			std::cout << "final path exists" << std::endl;
			if (bf::is_directory(finalPath))
			{
				std::cout << "final path is dir" <<std::endl;
				cpDirMode = true;
			}
			else
			{
				std::cout << "final path is file" <<std::endl;
			}
		}


	      for (int i = optind; i < argc; ++i)
		{
		}
	}
	else
	{
		usage();
	}
      return toReturn;
}

void usage()
{
	std::cout << "usage: cp [-R [-H | -L | -P]] [-f | -i | -n] [-alpv] source_file target_file" << std::endl <<
			"       cp [-R [-H | -L | -P]] [-f | -i | -n] [-alpv] source_file ... target_directory" << std::endl;
//	exit(EX_USAGE);
}

