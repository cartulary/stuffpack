#include <iostream>
#include <math.h>
#include "../libhello/libhello.h"

/* only accpet the CLI arguments */
int main (int argc, char *argv[])
{
	int toCheck;

	if (argc < 2)
	{
		std::cerr << "sorry" << std::endl;
		return 1;
	}

	/* get the first integer; maybe check them all eventually? */
	toCheck = atoi(argv[1]);

	bool isPrimeResult = isPrime(toCheck);
	/* print our result -> only print 'npt' if we not prime*/
	std::cout << ((isPrimeResult) ? "" : "not ") << "prime" << std::endl;
	return 0;
}
