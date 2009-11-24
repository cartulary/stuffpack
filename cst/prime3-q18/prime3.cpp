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
#include <math.h>
#include <gmp.h>
#include <gmpxx.h>


int sumDigits(int num);
bool isPrime(int num);

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

bool isPrime(int num)
{
	/* we only check until the square root */
	int maxFactor = static_cast<int>(floor(sqrt(num)));

	/* for == 2 and <1 use the "else" */
	if (num >= 3 && num %2 != 0)
	{
		/* check for all odd numbers  */
		for (int i = 3; i <= maxFactor; i += 2)
		{
			/* check to see if we are prime */
			if (num % i == 0)
			{
				/* we are not prime; stop checking */
				return false;
			}
		}
	}
	else
	{
		if (num != 2)
		{
			return false;
		}
	}
	return true;
}
