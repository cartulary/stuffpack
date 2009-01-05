/* change in behavior with -bn */
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

bool catFile(const char *file);
bool doCatFile (istream &toCat);
inline const char *itos(int num);
string vStyle (string str);
string strReplace (string str, string old, string newStr);
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
			case 't':
				dispTabFlag = dispNotPrintingFlag = true;
			case 'v':
				dispNotPrintingFlag = true;
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

bool doCatFile (istream &toCat)
{
	if (! toCat)
	{
		return false;
	}
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
	return true;
}


bool catFile(const char *file)
{
	bool returnVal;
      ifstream toCat;
      toCat.open(file, ios::out);
	if (toCat.is_open())
      {
		returnVal = doCatFile(toCat);
	      toCat.close();
	}
	else
	{
		return false;
	}
	return returnVal;
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
