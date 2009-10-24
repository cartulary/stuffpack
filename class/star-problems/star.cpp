/**********************************************
 * Name: Star problem 10                      *
 * Purpose: Print a diamon using N rows	    *
 * Returns: 0 when argument exists; else 1    *
 * Parameters: N as first command line option *
 * Known bugs: 					    *
 * algo for spacing ignores # of chars in -c  *
 * compatibility:	N/A				    *
 * notes: this could be done better...	    *
 *********************************************/

#include <getopt.h>
#include <iostream>

void repeat_char(const char* to_print, int times);
void usage(char* prog);

// Created by the getopt library
extern char* optarg;

int main (int argc, char* argv[])
{
	long rows = 0;
	int c;
	const char* diamond_char= "*";
	// Lets get the command line arguments
	while (( c = getopt (argc, argv, "c:n:")) != -1)
	{
		switch (c)
		{
			case 'c':
				diamond_char=optarg;
				break;
			case 'n':
				// I think I should do some sanity testing here...
				rows = strtol(optarg, NULL, 10);
				break;
			default:
				usage(argv[0]);
				return 1;
				break;
		}
	}
	/* if we don't have a -n argument */
	if (rows == 0)
	{
		usage(argv[0]);
		return 1;
	}
	if ( rows % 2 == 0)
	{
		// if we repeat the middle line it looks weird; if we don't then it also looks weird
		// I'm tempted to not even allow even sized diamonds
		std::cerr << "An even sized diamond is ambiguous..." << std::endl;
	}
	// We want the first command line option; argv[0] == name thaat program is executed with
	int cols =1;

	/* because we use repeat_char we don't need a col counter */
	int row;

	// each time out add how many stars?
	int amt_to_add = 2;

	// Odd values with <= will print extra line; lets see if we could fix this.
	for (row = 0; row < rows ; ++row)
	{
		int space_cols = (rows/2) - (cols /2);
		if (cols > 0)
		{
			// If cols == 0 (the last line of even rows) don't print anything
			repeat_char(" ", space_cols);
			repeat_char(diamond_char, cols);
			std::cout << std::endl;
		}

		if (row+1 == (rows / 2) && (rows % 2) == 0)
		{
			//repeat the row if we have an even number of rows
			// and we are in the middle.
			repeat_char(" ", space_cols);
			repeat_char(diamond_char, cols);
			std::cout << std::endl;
			amt_to_add=-2;
		}
		cols += amt_to_add;
            if (row +1 > (rows /2) -1)
            {
                  amt_to_add = -2;
            }
	}
	return 0;
}

/**********************************************
 * Name:    repeat_char                       *
 * Purpose: print specific char[] N times     *
 * Parameters: to_print (char[]), times (N)   *
 * Known bugs: none      			    *
 * notes: start from 1; use "<=" for	    *
 *	readability reasons			    *
 *********************************************/
void repeat_char(const char* to_print, int times)
{
	for (int counter = 1; counter <= times; ++counter)
	{
		std::cout << to_print;
	}
}

/**********************************************
 * Name:    usage                             *
 * Purpose: Prints usage information to stderr*
 * Parameters: the name of the program	    *
 *	(always pass argv[0])			    *
 *********************************************/
void usage(char* prog)
{
	std::cerr << "usage: "  << prog << " -n rows [-c string ]" << std::endl;
	std::cerr << std::endl;
	std::cerr << "\t -n \t number of rows to print in the diamond" << std::endl;
	std::cerr << "\t -c \t what character/string to print diamond with " << std::endl;
}
