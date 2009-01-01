/* change in behavior with -bn */
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

bool numLineFlag = false, allLineNumFlag = false, squeezeBlankFlag = false;

using namespace std;
int main(int argc, char *argv[])
{
	int c;
	int toReturn = 0;
      while ((c = getopt (argc, argv, "benstuv")) != -1)
	{
      	switch (c)
		{
			case 'b':
				numLineFlag = true;
				break;
			case 'n':
				allLineNumFlag = true;
				numLineFlag = true;
				break;
			case 's':
				squeezeBlankFlag = true;
				break;
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
				toReturn = 1;
			}
		}
		else
		{
			printf("stdin!\n");
		}
	}
      return toReturn;
}

bool catFile(char *file)
{
	bool lastLineFull = true;
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
				if (line.size() != 0)
				{
					lastLineFull = true;
	                  	printf("%d %s\n", lineNum, line.c_str());
					++lineNum;
				}
				else
				{
					if ( ! squeezeBlankFlag)
					{
						if (allLineNumFlag)
						{
							printf("%d\n",lineNum);
							++lineNum;
						}
						else
						{
							printf("\n");
						}
					}
					lastLineFull = false;
				}
			}
			else
			{
					/*TODO -s*/
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
