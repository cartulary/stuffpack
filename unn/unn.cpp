#include <iostream>
#include <vector>
#include <string.h>
#include <unistd.h>

#define FALSE	0
#define TRUE	1
#define FILE_READ_OK 0

using namespace std;
int main(int argc, char* argv[])
{
      vector<string> files; 
	int i;
	bool debug = FALSE;
	if (argc > 1)
	{
		for (i = 1 ; i <= argc - 1 ; i++)
		{
			if (strcmp((char*)argv[i],"-debug"))
			{
				files.push_back(argv[i]);
			}
			else
			{
				debug = TRUE;
			}
		}
	}
	else
	{
		return 0;
	}
	for (i = 0; i <= files.size() - 1 ; i++)
	{
		if (eaccess(files.at(i).c_str(),R_OK) == FILE_READ_OK)
		{
			cerr << "fatal error: " << files.at(i) << " exists" << endl;
		}
		else
		{
			if (debug)
			{
                  	cout << "starting execution of " << files.at(i) << " ..." << endl;
                  	cout << "we are done" << endl;
			}
		}
	}
	return 0;
}
