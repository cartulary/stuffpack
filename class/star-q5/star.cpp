/**********************************************
 * Name: Star problem 5                       *
 * Purpose: see picture              	    *
 * Returns: 0 always				    *
 *********************************************/

#include <iostream>

void repeat_char(const char* to_print, int times);
void makeRow(int spaces, int stars);

int main (int argc, char* argv[])
{
	int rows = 0;
	do
	{
		// don't use getopt or check for sanity for shortness of code...
		std::cin >>rows;
	} while (rows==0);

	int row;
	for (row = 1; row <= rows; ++row)
	{
		int big_print = rows - row + 1;
		// first triangle
		makeRow(0, row);
		// second triangle
		makeRow(big_print, big_print);
		// number three
		makeRow(big_print + row, row);
		// number four
		makeRow(row, big_print);
		std::cout << std::endl;
	}
}

/**********************************************
 * Name:    makeRow                           *
 * Purpose: prints row of the triangle        *
 * Parameters: number of spaces and stars     *
 * Known bugs: none      			    *
 *********************************************/
void makeRow(int spaces, int stars)
{
	repeat_char(" ", spaces);
	repeat_char("*", stars);
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
