// This source code is release under the CMU License.

#include <fstream>
#include <iterator>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

void signal_handler(int signal);

bool appendFlag = false, ignoreSignalFlag = false;

using namespace std;
int main(int argc, char *argv[])
{
	/* register the signal handler */
	/* why won't SIG_IGN work?	*/
	signal(SIGINT, signal_handler);

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
	/* open the files and assign them to elements in a vector */
	std::vector<std::ofstream*> fileList;
      if (argc > 1)
      {
		fileList.resize (argc);
		for(int i = 1; i < argc; ++i)
		{
			//I need to find a better way to do this?  Is there a way to keep a pointer to the "mode"?
			if (appendFlag)
			{
				//fileList.push_back(new std::ofstream(argv[i],ios::app | ios::binary));
    				fileList[i] = new std::ofstream(argv[i],ios::app | ios::binary);
			}
			else
			{
                        //fileList.push_back(new std::ofstream(argv[i],ios::out | ios::binary));
                        fileList[i] = new std::ofstream(argv[i],ios::out | ios::binary);
			}
		}
      }

	/* start reading input */
	string line;
	while ( ! cin.eof() )
	{
		getline(cin, line);
		if (argc > 1)
		{
			for (int i = 1; i < argc; ++i)
			{
				//  don't use .at() becauyse we know we are in bounds
				*fileList.at(i) << line << endl;
				//fileList[i]->write(line.c_str(), line.length() + 1);
			}

			/*
			for (std::vector<std::ofstream*>::iterator it = fileList.begin(); it != fileList.end(); ++it)
			{
				(*it)->write(line.c_str(),line.length() + 1);
			}*/

		}
		cout << line << endl;
	}
	return 0;
}

/**********************************************
 * Name:    singal_handler                    *
 * Purpose: handle signals; ignore sigint     *
 * Returns: nothing                           *
 * Parameters: int - which signal did we get  *
 * compatibility: tee -i	                *
 *********************************************/

void signal_handler(int signal)
{
	/* if we are  SIGINT and -i has been set ignore it else: */
	if (! (signal == SIGINT && ignoreSignalFlag) )
	{
		exit(0);
	}
}
