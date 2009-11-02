/*
     wc -- word, line, character, and byte count
*/
// This source code is release under the CMU License.
/* change in behavior with -bn */
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "fileCount.cpp"

bool wcFile(const char *file);
void doWcFile (std::istream &toWc);

/* make these flags default to false */
bool wordFlag = false, lineFlag = false, charFlag = false, byteFlag = false, longestLineFlag = false;

int totalChars = 0, totalLines = 0, totalWords = 0, totalLongestLine = 0;

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
	/* if no flags are set; make the default flags true */
	if (! (charFlag || lineFlag || byteFlag || wordFlag || longestLineFlag) )
	{
		charFlag = lineFlag = byteFlag = wordFlag = true;
	}
	/* If we have files on command line - display them; else just display std::cin once.*/
	if (argc > 1)
	{
		for (int i = optind; i < argc; ++i)
		{
			/* if what we have is not stdin deal with it as a file */
			if ( strcmp(argv[i] , "-") != 0 )
			{
				if ( ! wcFile(argv[i]) )
				{
					/* exact message produced by BSD wc */
	      			std::cerr << "wc: " << argv[i] << ": open: No such file or directory" << std::endl;
					toReturn = 1;
				}
				else
				{
					/* we don't pass the filename so print it here */
					std::cout << argv[i] << std::endl;
				}
			}
			else
			{
				/* we have stdin so go directly to "wc" */
				doWcFile(std::cin);
			}
		}
	}
	else
	{
		doWcFile(std::cin);
	}
	if (argc > 2)
	{
		std::cout << "\t";
		if (lineFlag)
		{
			std::cout << totalLines << "\t";
		}
		if (wordFlag)
		{
			std::cout << totalWords << "\t";
		}
		if (charFlag)
		{
			std::cout << totalChars << "\t";
		}
		if (longestLineFlag)
		{
			std::cout << totalLongestLine << " ";
		}
		std::cout << "total" << std::endl;
	}
	return toReturn;
}
/**********************************************
 * Name:    doWcFile                          *
 * Purpose: perform the "wc" action to file   *
 * Returns: nothing	 		          *
 * Parameters: istream - open isstream to file*
 * Known bugs: many unworking features;       *
 * compatibility: very limited                *
 * notes: keep some kind of pointer to an     *
 *	array of the const data that main()     *
 *	could use later? something else?	    *
 *********************************************/

void doWcFile (std::istream &toWc)
{
	fileCount *wcObj = new fileCount(toWc);

	/* display the result; what I'd really like to do is return this in some sort of array form...*/
	std::cout << "\t";
	int current = wcObj->getNumLines();
	if (totalLongestLine < current)
	{
		totalLongestLine = current;
	}
	if (lineFlag)
	{
		/* lines fetched above */
		totalLines += current;
		std::cout << current << "\t";
	}
	if (wordFlag)
	{
		current = wcObj->getNumWords();
		totalWords += current;
		std::cout << current << "\t";
	}
	if (charFlag)
	{
		current = wcObj->getNumChars();
		totalChars += current;
		std::cout << current << "\t";
	}
	if (longestLineFlag)
	{
		std::cout << wcObj->getLongestLineLen() << " ";
	}
	/*  filename printed by calling function */
}

/**********************************************
 * Name:    wcFile                            *
 * Purpose: perform the error checking        *
 * Returns: nothing                           *
 * Parameters: char* - string to file name    *
 *********************************************/

bool wcFile(const char *file)
{
      std::ifstream toWc;
      toWc.open(file, std::ios::in);
	if ( ! toWc)
      {
		return false;
	}
	doWcFile(toWc);
      toWc.close();
	return true;
}
