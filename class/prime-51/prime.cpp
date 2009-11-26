#include <iostream>
#include <math.h>
#include "../../libhello/libhello.h"

/* only accpet the CLI arguments */
int main (int argc, char *argv[])
{
	const int num_primes = 51;
	int primelist[num_primes];
	int primeCount=0;
	int num=0;

	while (primeCount < num_primes)
	{
		bool isPrimeResult = isPrime(num);
		if (isPrimeResult)
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