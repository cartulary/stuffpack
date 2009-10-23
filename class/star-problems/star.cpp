/**********************************************
 * Name: Star problem 10                      *
 * Purpose: Print a diamond using stars	    *
 * Returns: always 0                          *
 * Parameters: Single input @ start		    *
 * Known bugs: none 				    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/

#include <iostream>

int main (int argc, char* argv[])
{
	int rows;
	rows = atoi(argv[1]);
	int row = 0;
	int amount = 1;
	int amt_to_add = 2;
	for (; row < rows; ++row)
	{
		int col;
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
		if (row + 1 > (rows /2) -1)
		{
			amt_to_add = -2;
		}
	}
	return 0;
}
