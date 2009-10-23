/**********************************************
 * Name: Star problem 10                      *
 * Purpose: Print a diamon using N rows	    *
 * Returns: 0 when argument exists; else 1    *
 * Parameters: N as first command line option *
 * Known bugs: extra line printed with odd n  *
 * compatibility:	N/A				    *
 * notes: this could be done better...	    *
 *********************************************/

#include <iostream>

void repeat_char(char to_print, int times)
{
	for (int counter = 1; counter <= times; ++counter)
	{
		std::cout << to_print;
	}
}

int main (int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please choose a value..." << std::endl;
		return 1;
	}

	// We want the first command line option; argv[0] == name thaat program is executed with
	long rows = strtol(argv[1], NULL, 10);
	int cols = 1;

	int row, col;

	// each time out add how many stars?
	int amt_to_add = 2;

	// Odd values with <= will print extra line; lets see if we could fix this.
	for (row = 0; row <= rows ; ++row)
	{

		int space_cols = (rows/2) - (cols /2);
		for (col = 1; col <= space_cols; ++col)
		{
			std::cout << " ";
		}
		for (col = 1; col <= cols; ++col)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
		cols += amt_to_add;
            if (row +1 > (rows /2) -1)
            {
                  amt_to_add = -2;
            }
	}
	return 0;
}
