#include <iostream>
#include <math.h>

bool isPrime(int num);

/* only accpet the CLI arguments */
int main (int argc, char *argv[])
{
	int num;

	if (argc < 2)
	{
		std::cerr << "sorry" << std::endl;
		return 1;
	}

	/* get the first integer; maybe check them all eventually? */
	num = atoi(argv[1]);


	/* print our result -> only print 'npt' if we not prime*/
	std::cout << ((isPrime(num)) ? "" : "not ") << "prime" << std::endl;
	return 0;
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
