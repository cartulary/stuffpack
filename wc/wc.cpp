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

bool wordFlag = false, lineFlag = false, charFlag = false, byteFlag = false, onlyLongestLine = false;

int main(int argc, char *argv[])
{
	int c;
	int toReturn = 0;
      while ((c = getopt (argc, argv, "Lclmw")) != -1)
	{
      	switch (c)
		{
			case 'L':
				onlyLongestLine = true;
				break;
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
	long int lineNums = 0;
	long int charNums = 0;

	string line;

	while (! toWc.eof() )
	{
		getline(toWc, line);
		charNums += line.size();
		++lineNums;
	}
	cout << "line nums:" << lineNums << " " << "char nums:" << charNums << endl;
}


bool wcFile(const char *file)
{
      ifstream toWc;
      toWc.open(file, ios::in);
	if ( ! toWc)
      {
		return false;
	}
	doWcFile(toWc);
      toWc.close();
	return true;
}
