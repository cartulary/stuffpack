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

int sumHappyDigits(long num);
bool isPrime(long num);
bool isHappy(long num);

int main (int argc, char* argv[])
{
	long i;
	int answerCount=0;
	int primeAnswerCount=0;
	int sumHappyPrimes=0;
	for (i=1; i < 300000; ++i)
	{
		/*
			We want the number of positive happy numbers < 300,000
		*/

		if (isHappy(i))
		{
			std::cout << i;
			++answerCount;
			if (isPrime(i))
			{
				/* we want the sum of the first 10,000 happyPrimes */
				std::cout << "*";
				++primeAnswerCount;
				if (primeAnswerCount <= 10000)
				{
					sumHappyPrimes += i;
				}
			}
			std::cout << "\n";
		}

	}
	std::cerr << "Answer=" << answerCount << " primeAnswer="<< primeAnswerCount << " sumPrimes= "<< sumHappyPrimes << std::endl;
	return 0;
}

bool isHappy(long num)
{
	int happyValue = sumHappyDigits(num);
	if (happyValue == 1)
	{
		return true;
	}
	return false;
}

int sumHappyDigits(long num)
{
	int sum=0;
//	std::cout << num << " = ";
	while (num > 0)
	{
//		std::cout << num % 10 << "^2 (" << pow(num%10,2) << ") ";
		sum += pow(num % 10,2);
		num /= 10;
	}
//	std::cout << "\n";
	if (sum < 10)
	{
		return sum;
	}
	return sumHappyDigits(sum);
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
