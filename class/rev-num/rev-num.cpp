/**********************************************
 * Name: Reverse number                       *
 * Purpose: Input a number; reverse it	    *
 * Returns: 1 on error; else 0                *
 * Parameters: argv[1]==long			    *
 * Known bugs: None				    *
 *********************************************/

#include <iostream>

int main (int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cerr << "Please choose a number" << std::endl;
		return 1;
	}

	long num = strtol(argv[1], NULL, 10);
	while (num != 0)
	{
		std::cout << num % 10;
		num /= 10;
	}
	std::cout << std::endl;
	return 0;
}
