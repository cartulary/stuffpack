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

	/* initialize to true unless proven false*/
	bool isPrime = true;

	/* for == 2 and <1 use the "else" */
	if (toCheck > 2 && toCheck %2 != 0)
	{
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
	else
	{
		isPrime = false;
		if (toCheck == 2)
		{
			isPrime = true;
		}
	}

	/* print our result -> only print 'npt' if we not prime*/
	std::cout << ((isPrime) ? "" : "not ") << "prime" << std::endl;
	return 0;
}
