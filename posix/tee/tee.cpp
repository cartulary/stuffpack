/* This source code is release under the CMU License. */

#include <fstream>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

bool appendFlag = false, ignoreSignalFlag = false;

using namespace std;
int main(int argc, char *argv[])
{
	std::vector<std::ofstream*> fileList;

      int c;
	/* start parsing options */
      while ((c = getopt (argc, argv, "ai")) != -1)
     	{
            switch (c)
            {
                  case 'a':
                        appendFlag = true;
                        break;
                  case 'i':
                        ignoreSignalFlag = true;
				break;
			default:
				break;
		}
	}

	/* register the signal handler */
	/* why won't SIG_IGN work?	*/
	if (ignoreSignalFlag)
	{
		signal(SIGINT, SIG_IGN);
	}

	// lets make sure we have enouph room for all the CLI files...
	fileList.reserve (argc - optind);
	/* since the CLI index includes options we want to maintain a count of files */
	int fileCount = 0;
	/* add files to fileList; */
	for (int i = optind; i < argc; ++i )
	{
		//I need to find a better way to do this?  Is there a way to keep a pointer to the "mode"?
		if (appendFlag)
		{
            	fileList.push_back (new std::ofstream(argv[i], ios::app | ios::binary));
		}
            else
            {
                  fileList.push_back (new std::ofstream(argv[i], ios::out | ios::binary));
            }
		/* we use this later to determine how many files we have... */
		++fileCount;
	}

	/* start reading input */
	string line;
	while ( ! cin.eof() )
	{
		getline(cin, line);
		/* only write to files if we have files....*/
		if (fileCount > 0)
		{
			for (std::vector<std::ofstream*>::size_type i = 0; i < fileList.size(); ++i)
			{
				//  don't use .at() becauyse we know we are in bounds
				*fileList[i] << line << endl;
			}
		}
		cout << line << endl;
	}
	return 0;
}
