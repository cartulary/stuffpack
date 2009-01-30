#include <fstream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
bool appendFlag = false, ignoreSignalFlag = false;
int main(int argc, char *argv[])
{
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
			//ios::app for appendMode
    			fileList[i] = new std::ofstream(argv[i]);
		}
      }
	string line;
	while ( ! cin.eof() )
	{
		getline(cin, line);
		if (argc > 1)
		{
            	for(int i = 1; i < argc; ++i)
			{
				fileList.at(i)->write(line.c_str(),line.length());
			}
		}
		cout << line << endl;
	}
	return 0;
}
