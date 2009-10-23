/**********************************************
 * Name: Star problem 10                      *
 * Purpose: Print a diamon using N rows	    *
 * Returns: 0 when argument exists; else 1    *
 * Parameters: N as first command line option *
 * Known bugs: extra line printed with odd n  *
 * compatibility:	N/A				    *
 * notes: this could be done better...	    *
 *********************************************/

#include <getopt.h>
#include <iostream>

void repeat_char(const char* to_print, int times);

extern char* optarg;

int main (int argc, char* argv[])
{
	long rows = 2;
	int c;
	const char* diamond_char= "*";
	while (( c = getopt (argc, argv, "c:n:")) != -1)
	{
		switch (c)
		{
			case 'c':
				diamond_char=optarg;
				break;
			case 'n':
				rows = strtol(optarg, NULL, 10);
				break;
			default:
				break;
		}
	}
	// We want the first command line option; argv[0] == name thaat program is executed with
	int cols =1;

	/* because we use repeat_char we don't need a col counter */
	int row;

	// each time out add how many stars?
	int amt_to_add = 2;

	// Odd values with <= will print extra line; lets see if we could fix this.
	for (row = 0; row <= rows ; ++row)
	{
		int space_cols = (rows/2) - (cols /2);
		repeat_char(" ", space_cols);
		repeat_char(diamond_char, cols);
		std::cout << std::endl;
		cols += amt_to_add;
            if (row +1 > (rows /2) -1)
            {
                  amt_to_add = -2;
            }
	}
	return 0;
}

void repeat_char(const char* to_print, int times)
{
	for (int counter = 1; counter <= times; ++counter)
	{
		std::cout << to_print;
	}
}
