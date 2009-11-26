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
#include "../../libhello/libhello.h"

int sumDigits(long num);

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
