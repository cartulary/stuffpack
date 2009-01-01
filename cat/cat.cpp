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
bool dispNotPrintingFlag = false, dispDollarFlag = false, dispTabFlag = false;

using namespace std;
int main(int argc, char *argv[])
{
	int c;
	int toReturn = 0;
      while ((c = getopt (argc, argv, "benstuv")) != -1)
	{
      	switch (c)
		{
			case 'n':
				allLineNumFlag = true;
				//no break
			case 'b':
				numLineFlag = true;
				break;
			case 'e':
				dispDollarFlag = dispNotPrintingFlag = true;
			case 't': /* Display non-printing characters (see the -v option), and display
             tab characters as `^I' */ // include -v
			case 'v':
				/* Display non-printing characters so they are visible.  Control
             characters print as `^X' for control-X; the delete character
             (octal 0177) prints as `^?'.  Non-ASCII characters (with the high
             bit set) are printed as `M-' (for meta) followed by the character
             for the low 7 bits. */
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
			fprintf(stderr, "can not deal with stdin");
		}
	}
      return toReturn;
}

bool catFile(char *file)
{
	bool lastLineFull = true;
	string line;
	string postline = "";
      if (dispDollarFlag)
	{
		postline = "$";
	}
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
	                  	printf("%d %s%s\n", lineNum, line.c_str(),postline.c_str());
					++lineNum;
				}
				else
				{
					if ( ! squeezeBlankFlag || lastLineFull)
					{
						if (allLineNumFlag)
						{
							printf("%d%s\n",lineNum,postline.c_str());
							++lineNum;
						}
						else
						{
							printf("%s\n",postline.c_str());
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
					printf("%s\n", line.c_str());
				}
				else
				{
	                        if ( ! squeezeBlankFlag || lastLineFull)
                              {
						printf("\n");
                              }
                              lastLineFull = false;
				}
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
