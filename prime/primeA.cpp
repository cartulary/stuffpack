#include <iostream>
#include <math.h>

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

	/* we only check until the square root */
	int maxFactor = floor(sqrt(toCheck));

	/* initialize to true until we test for even numbers*/
	bool isPrime = false;

	/* check for divide by 2 first */
	if ( toCheck % 2 != 0)
	{
		/* we assume we are prime until proven wrong*/
		isPrime = true;
		/* check for all odd numbers  */
		for (int i = 3; i <= maxFactor; i += 2)
		{
			/* check to see if we are prime */
			if (toCheck % i == 0)
			{
				isPrime = false;
				/* we are not prime; stop checking */
				break;
			}
		}
	}

	/* print our result -> only print 'npt' if we not prime*/
	std::cout << ((isPrime) ? "" : "not ") << "prime" << std::endl;
	return 0;
}