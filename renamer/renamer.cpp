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

static int one(struct dirent* dir);
std::string moveTo(std::string filename, bool confirmed);

enum doChoice {
	CONFIRM_MOVE,
	DENY_MOVE,
	LESS_PATH
};

int main (int argc, char* argv[])
{
	char* folder = ".";
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
				std::cout << "moved to " << moveTo(eps[cnt]->d_name,false) << "/ \n";
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

std::string moveTo(std::string filename, bool confirmed)
{
	std::string::size_type idx;

	idx = filename.find_last_of('.');
	if(idx != std::string::npos)
	{
    	std::string extension = filename.substr(0,idx);
		return extension;
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
