#include "fileCount.h"

fileCount::fileCount(std::istream &file) : lineNums(0), charNums(0), words(0), longestLine (0)
{
	unsigned int lineLen;
	bool lastSpace = false; /* use so double spaces are not counted as words */
	//bool curCharIsSpace = false;
	std::string line;

	while (! file.eof() )
	{
		//lastSpace = false;
		getline(file, line);
		/* does not deal with -c vs -m yet! */
		lineLen = line.size();
		charNums += lineLen + 1;
		++lineNums;
//		std::cout << lineNums << "\t"<< line <<std::endl;

		if (lineLen > longestLine)
		{
			longestLine = lineLen;
		}

		for(unsigned int i = 1; i < lineLen; ++i)
		{
			/* we are not going to use .at() because we know we are in range */
			if (iswspace(line[i]))
			{
				if (!lastSpace)
				{
					++words;
				}
				lastSpace = true;
			}
			else
			{
				lastSpace = false;
			}
		}
	}

	/* we count one extra character and line - remove it*/
	--charNums;
	--lineNums;

}

unsigned long int fileCount::getLongestLineLen()
{
	return longestLine;
}

unsigned long int fileCount::getNumLines()
{
	return lineNums;
}

unsigned long int fileCount::getNumChars()
{
	return charNums;
}

unsigned long int fileCount::getNumWords()
{
	return words;
}
