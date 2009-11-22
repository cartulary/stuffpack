#include <iostream>
#include <math.h>

bool checkPrime(int num);

/* only accpet the CLI arguments */
int main (int argc, char *argv[])
{
	const int num_primes = 51;
	int primelist[num_primes];
	int primeCount=0;
	int num=0;

	while (primeCount < num_primes)
	{
		bool isPrime = checkPrime(num);
		if (isPrime)
		{
			primelist[primeCount] = num;
			++primeCount;
		}
		++num;
	}

	int i;
	long sum =0;
	for (i=0; i < num_primes; ++i)
	{
		/* the middle */
		if (i==25)
		{
			std::cout << "*";
		}
		std::cout << primelist[i] << " ";
		sum += primelist[i];
	}
	std::cout << std::endl;
	std::cout << sum << std::endl;

	return 0;
}

bool checkPrime(int num)
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
