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


using namespace std;
bool appendFlag = false, ignoreSignalFlag = false;
int main(int argc, char *argv[])
{
	/* register the signal handler */
	signal(SIGINT, signal_handler);

      int c;
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
				cerr << "broken" << endl;
		}
	}
	std::vector<std::ofstream*> fileList;
      if (argc > 1)
      {
		fileList.resize (argc - 1);
		for(int i = 1; i < argc; ++i)
		{
			//I need to find a better way to do this?  Is there a way to keep a pointer to the "mode"?
			if (appendFlag)
			{
    				fileList[i] = new std::ofstream(argv[i],ios::app | ios::binary);
			}
			else
			{
                        fileList[i] = new std::ofstream(argv[i],ios::out | ios::binary);
			}
		}
      }
	string line;
	while ( ! cin.eof() )
	{
		getline(cin, line);
		for (std::vector<std::ofstream*>::iterator it = fileList.begin(); it != fileList.end(); ++it)
		{
			(*it)->write(line.c_str(),line.length());
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
