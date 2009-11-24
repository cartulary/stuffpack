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


int sumDigits(long num);
bool isPrime(long num);

int main (int argc, char* argv[])
{
	long i;
	int answerCount=0;
	for (i=0; i < 1000000; ++i)
	{
		/* We want the number of primes below 1,000,000 that
		*  have the sum of their digits equal to the number
		*  of days in a fortnight.
		*/	
		if (isPrime(i) && sumDigits(i) == 14)
		{
			std::cout << i << "\n";
			++answerCount;
		}
	}
	std::cout << "Answer=" << answerCount << std::endl;
	return 0;
}

int sumDigits(long num)
{
	int sum=0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

bool isPrime(long num)
{
	/* we only check until the square root */
	long maxFactor = static_cast<long>(floor(sqrt(num)));

	/* for == 2 and <1 use the "else" */
	if (num >= 3 && num %2 != 0)
	{
		/* check for all odd numbers  */
		for (long i = 3; i <= maxFactor; i += 2)
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
