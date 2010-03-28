/********************************************
 * Name: file renamer                       *
 * Purpose: moves files in a directory into	*
			sub directories					*
 * Returns: 0 always                        *
 * Parameters: directory to work with  		*
 * Known bugs:					    		*
 * notes:						    		*
 *******************************************/

#include <iostream>
#include <sysexits.h>
#include <string>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>

enum doChoice {
	FIRST_ASK,
	CONFIRM_MOVE,
	DENY_MOVE
};

static int one(struct dirent* dir);
std::string moveTo(std::string filename, doChoice confirmed);

doChoice confirm();

//I know, globals are a bad idea :(
char* folder = ".";
int main (int argc, char* argv[])
{
	/* if we specified a folder... */
	if (1 != argc)
	{
		//in theory I could run this program over all of them ... but I don't want to
		folder = argv[1];
	}

	int i;
	for (i=0; folder[i]!=0; ++i);

	if (folder[i-1] != '/')
	{
		//its ok to leak this till the end b/c we need it anyway
		char* newfolder = new char[i+1];
		strcpy(newfolder, folder);
		newfolder[i] = '/';
		folder = newfolder;
	}

	std::cout << "folder is " << folder << "\n\n";

	struct dirent **eps;
	int n = scandir (folder, &eps, one, alphasort);
	if (n > 0)
	{
		int cnt;
		for (cnt = 0; cnt < n; ++ cnt)
		{
			/* Are we a hidden file? if so skip it */
			if ((eps[cnt]->d_name)[0] != '.')
			{
				std::cout << eps[cnt]->d_name << " ";
				std::string newDir = moveTo(eps[cnt]->d_name, FIRST_ASK);
				if ("" != newDir)
				{
					std::cout << "moving to " << newDir << "/\n";
					doChoice val = confirm();
					static_cast<void>(moveTo(eps[cnt]->d_name, val));
				}
			}
		}
		std::cout << "\n";
	}
	else
	{
		std::cerr << "\nFailed to open directory\n";
		return EX_IOERR;
	}
	return EX_OK;
}

std::string moveTo(std::string filename, doChoice confirmed)
{
	std::string::size_type idx;

	idx = filename.find_first_of('.');
    std::string dirpart = filename.substr(0,idx);

	if(idx != std::string::npos)
	{
		if (CONFIRM_MOVE == confirmed)
		{
			// this is a very simple test for file existance...
			// I should test for file existance + ability to write...
			if ( access( dirpart.c_str(), 0) == 0 )
			{
				std::cout << "Directory already exists\n";
			}
			else
			{
				errno = 0;
				int ret = mkdir (dirpart.c_str(),0777);
				std::cout << "We returned " << ret << "with" << errno <<" and " << strerror(errno) << " \n";
			}
			std::string newname = dirpart + "/" + filename;
			std::cout << "\nrenaming " << filename << " to " << newname << "\n";
			int ret = rename(filename.c_str(), newname.c_str());
			std::cout << "We returned " << ret << "with" << errno <<" and " << strerror(errno) << " \n";
		}
		return dirpart;
	}
	else
	{
		return "";
	    // No extension found
	}

}

/* include ALL files in the list of things for now....*/
static int one(struct dirent* dir)
{
	return 1;
}

doChoice confirm()
{
	std::cout << "Confirm? [y/N]: ";
	char choice;
	std::cin >> choice;
	if (tolower(choice) == 'y')
	{
		return CONFIRM_MOVE;
	}
	return DENY_MOVE;
}
