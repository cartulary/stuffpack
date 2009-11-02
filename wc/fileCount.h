/*
	This file can (and should) be easily extended to provide many other statistics about
	the relevent file.	At some point I should make a "file stats" program based
	on this class and provide many other interestiing statistics
*/
#ifndef FILECOUNT_H
#define FILECOUNT_H

#include <fstream>
#include <iostream>

/*
	This class will handle the opening/counting of a file while the core program will use this class
	to provide the wc service.
*/
class fileCount
{
	public:
		fileCount(std::istream &file);
		unsigned long int getNumLines();
		unsigned long int getNumChars();
		unsigned long int getNumWords();
		unsigned long int getLongestLineLen();
	private:
		unsigned long int lineNums;
		unsigned long int charNums;
		unsigned long int words;
		unsigned long int longestLine;
};
#endif
