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

bool wordFlag = false, lineFlag = false, charFlag = false, byteFlag = false, longestLineFlag = false;

int main(int argc, char *argv[])
{
	int c;
	int toReturn = 0;
      while ((c = getopt (argc, argv, "Lclmw")) != -1)
	{
      	switch (c)
		{
			case 'L':
				longestLineFlag = true;
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
	unsigned long int lineNums = 0;
	unsigned long int charNums = 0;
	unsigned long int words = 1; /* begin at one because we look for spaces; not words */
	unsigned long int longestLine = 0;
	bool lastSpace = false; /* use so double spaces are not counted as words */
	bool curCharIsSpace = false;
	string line;

	while (! toWc.eof() )
	{
		getline(toWc, line);
		/* does not deal with -c vs -m yet! */
		unsigned int lineLen = line.size();
		charNums += lineLen;
		++lineNums;
		if (lineLen > longestLine)
		{
			longestLine = lineLen;
		}
		for(unsigned int i = 0; i < lineLen; ++i)
		{
			/* use iswspace? */
			/* we are not going to use .at() because we know we are in range */
			curCharIsSpace = isspace(line[i]);
			if (curCharIsSpace && !lastSpace)
			{
				++words;
			}
			else
			{
				if (!curCharIsSpace)
				{
					lastSpace = false;
				}
			}
		}
	}
	if (lineFlag)
	{
		cout << lineNums << " ";
	}
	if (wordFlag)
	{
		cout << words << " ";
	}
	if (charFlag)
	{
		cout << charNums << " ";
	}
	if (longestLineFlag)
	{
		cout << longestLine;
	}
	cout << endl;
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
