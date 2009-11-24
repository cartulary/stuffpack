/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/

#include <iostream>
int sumDigits(int num);

int main (int argc, char* argv[])
{
	std::cout<< sumDigits(415) << std::endl;
	return 0;
}

int sumDigits(int num)
{
	int sum=0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
