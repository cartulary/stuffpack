/* change in behavior with -bn */
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

bool wcFile(const char *file);
void doWcFile (istream &toWc);

bool wordFlag = false, lineFlag = false, charFlag = false, byteFlag = false;

int main(int argc, char *argv[])
{
	int c;
	int toReturn = 0;
      while ((c = getopt (argc, argv, "clmw")) != -1)
	{
      	switch (c)
		{
			case 'c':
				charFlag = true;
				break;
			case 'l':
				lineFlag = true;
				break;
			case 'm':
				byteFlag = true;
				break;
			case 'w':
				wordFlag = true;
				break;
			default:
				charFlag = lineFlag = byteFlag = wordFlag = true;
		}

	}
	/* If we have files on command line - display them; else just display cin once.*/
	if (argc > 1)
	{
	      for (int i = optind; i < argc; ++i)
		{
		if ( strcmp(argv[i] , "-") != 0 )
			{
				if ( ! wcFile(argv[i]) )
				{
	      			cerr << "wc: " << argv[i] << ": open: No such file or directory" << endl;
					toReturn = 1;
				}
			}
			else
			{
				doWcFile(cin);
			}
		}
	}
	else
	{
		doWcFile(cin);
	}
      return toReturn;
}

void doWcFile (istream &toWc)
{
	int lineNums;
	int charNums;
	int byteNums;

	string line;
	int lineNum = 1;
	while (! toWc.eof() )
	{
		getline(toWc, line);
		if (numLineFlag)
		{
			if (line.size() != 0)
			{
				lastLineFull = true;
				cout << lineNum << " " << line << postline.c_str() << endl;
				++lineNum;
			}
			else
			{
				if ( ! squeezeBlankFlag || lastLineFull)
				{
					if (allLineNumFlag)
					{
						cout << lineNum << " " << postline.c_str() << endl;
						++lineNum;
					}
				}
				lastLineFull = false;
			}
		}
		else
		{
       		if (line.size() != 0)
                  {
                  	lastLineFull = true;
				cout << vStyle(line).c_str() << postline.c_str() << endl;
			}
			else
			{
                  	if ( ! squeezeBlankFlag || lastLineFull)
                        {
					cout << postline.c_str() << endl;
                        }
                        lastLineFull = false;
			}
		}
   	}
}


bool wcFile(const char *file)
{
      ifstream toWc;
      toWc.open(file, ios::out);
	if ( ! toWc)
      {
		return false;
	}
	doCatFile(toWc);
      toWc.close();
	return true;
}
