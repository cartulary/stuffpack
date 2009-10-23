/**********************************************
 * Name: Star problem 10                      *
 * Purpose: Print a diamond using stars	    *
 * Returns: 0 when argument exists; else 1    *
 * Parameters: Single input @ start		    *
 * Known bugs: none 				    *
 * compatibility:	N/A				    *
 * notes: this could be done better...	    *
 *********************************************/

#include <iostream>

int main (int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please choose a value..." << std::endl;
		return 1;
	}
	long rows = strtol(argv[1], NULL, 10);
	int row, col;
	int amt_to_add = 2;
	int amount = 1;
	// Odd values with <= will print extra line; lets see if we could fix this.
	for (row = 0; row <= rows ; ++row)
	{

		int space_amt = (rows/2) - (amount /2);
		for (col = 1; col <= space_amt; ++col)
		{
			std::cout << " ";
		}
		for (col = 1; col <= amount; ++col)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
		amount += amt_to_add;
            if (row +1 > (rows /2) -1)
            {
                  amt_to_add = -2;
            }
	}
	return 0;
}
