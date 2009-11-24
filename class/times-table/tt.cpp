/**********************************************
 * Name: Times table                          *
 * Purpose: Prints out times table until 10   *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/

#include <iostream>
#include <iomanip>

int main (int argc, char* argv[])
{
	int i,j;
	const int max=10;
	for (i=0; i<= max; ++i)
	{
		for (j=0; j<max; ++j)
		{
			std::cout << std::setw(5) << i * j << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
