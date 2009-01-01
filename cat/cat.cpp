#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool catFile(char *file);
inline const char *itos(int num);

bool numLineFlag = false;

using namespace std;
int main(int argc, char *argv[])
{
	int c;
      while ((c = getopt (argc, argv, "benstuv")) != -1)
	{
      	switch (c)
		{
			case 'b':
				numLineFlag = true;
			case 'u':
				setbuf (stdout, NULL);
				break;
			default:
				cout << "options ignored" << endl;
		}

	}
      for (int i = optind; i < argc; i++)
	{
		if ( strcmp(argv[i] , "-") )
		{
			if ( ! catFile(argv[i]) )
			{
      			fprintf (stderr,"cat: %s: No such file or directory\n", argv[i]);
			}
		}
		else
		{
			printf("stdin!\n");
		}
	}
      return 0;
}

bool catFile(char *file)
{
	string line;
	ifstream toCat;
	int lineNum = 1;
	toCat.open(file, ios::out);

	if (toCat.is_open())
	{
		while (! toCat.eof() )
		{
			getline(toCat, line);
			if (numLineFlag)
			{
                  	printf("%d %s %s\n", line.size(), itos(lineNum), line.c_str());
				++lineNum;
			}
			else
			{
				printf("%s\n", line.c_str());
			}
    		}
		toCat.close();
		return true;
	}
	else
	{
		return false;
	}
}

inline const char *itos(int num)
{
	ostringstream oss;
	oss<<num;
	return oss.str().c_str();
}
