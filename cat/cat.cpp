/* change in behavior with -bn */
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

/* checks for the existance of the file and passes it to do */
bool catFile(const char *file);
/* cat the file */
void doCatFile (istream &toCat);
/* convert int to string */
inline const char *itos(int num);
/* convert unprintable characters; semi-broken */
string vStyle (string str);
/* replace a string... */
string strReplace (string str, string old, string newStr);
/* convert some more characters to ascii; 100% broken */
string asciify(const char *str ,int size);

bool numLineFlag = false, allLineNumFlag = false, squeezeBlankFlag = false;
bool dispNotPrintingFlag = false, dispDollarFlag = false, dispTabFlag = false;

int main(int argc, char *argv[])
{
	int c;
	int toReturn = 0;
      while ((c = getopt (argc, argv, "benstuv")) != -1)
	{
      	switch (c)
		{
			case 'n':
				allLineNumFlag = numLineFlag = true;
				break;
			case 'b':
				numLineFlag = true;
				allLineNumFlag = false; //compat with bsdcat (-bn)
				break;
			case 'e':
				dispDollarFlag = dispNotPrintingFlag = true;
				break;
			case 't':
				dispTabFlag = dispNotPrintingFlag = true;
				break;
			case 'v':
				dispNotPrintingFlag = true;
				break;
			case 's':
				/* don'r echo multiple blank lines at ones */
				squeezeBlankFlag = true;
				break;
			case 'u':
				/* not sure what this option is for */
				setbuf (stdout, NULL);
				break;
			default:
				break;
		}

	}
	/* If we have files on command line - display them; else just display cin once.*/
	if (argc > 1)
	{
	      for (int i = optind; i < argc; ++i)
		{
		if ( strcmp(argv[i] , "-") != 0 )
			{
				if ( ! catFile(argv[i]) )
				{
	      			cerr << "cat: " << argv[i] << ": No such file or directory" << endl;
					toReturn = 1;
				}
			}
			else
			{
				doCatFile(cin);
			}
		}
	}
	else
	{
		doCatFile(cin);
	}
      return toReturn;
}

void doCatFile (istream &toCat)
{
	bool lastLineFull = true;
	string line;
	string postline = "";
      if (dispDollarFlag)
	{
		postline = "$";
	}
	int lineNum = 1;
	while (! toCat.eof() )
	{
		getline(toCat, line);
		if (numLineFlag)
		{
			if (line.size() != 0)
			{
				lastLineFull = true;
				cout << lineNum << " " << vStyle(line).c_str() << postline.c_str() << endl;
				++lineNum;
			}
			else
			{
				/* if we squeeze blanks together ignore the rest of the blanks; else treat them like normal */
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

/**********************************************
 * Name:    catFile                           *
 * Purpose: perform the error checking        *
 * Returns: nothing                           *
 * Parameters: char* - string to file name    *
 *********************************************/

bool catFile(const char *file)
{
      ifstream toCat;
      toCat.open(file, ios::out);
	if ( ! toCat)
      {
		return false;
	}
	doCatFile(toCat);
      toCat.close();
	return true;
}

inline const char *itos(int num)
{
	ostringstream oss;
	oss<<num;
	return oss.str().c_str();
}


string vStyle (string str)
{
	string good;
	good = str;
	if (dispNotPrintingFlag)
	{
		if (dispTabFlag)
		{
			good = strReplace(str,"\t","^I");
		}
//		good = asciify(good.c_str(), good.size());
            good = strReplace(str,"\a","^G");
            good = strReplace(str,"\b","^H");
            good = strReplace(str,"\n","\\n");
            good = strReplace(str,"\f","\\f");
            good = strReplace(str,"\r","^M");
	}
	return good;
}

string strReplace(string str, string old, string newStr)
{
	string::size_type pos = 0;
    	while ( (pos = str.find(old, pos)) != string::npos)
	{
      	str.replace( pos, old.size(), newStr );
        	++pos;
    	}
	return str;
}

string asciify(const char *str ,int size)
{

	/*FIXME */

	for (int i = 0; i < size; ++i)
	{
		if (!isprint(str[i]))
		{
			cout << "die!" << endl;
		}
	}

	return  str;
}
