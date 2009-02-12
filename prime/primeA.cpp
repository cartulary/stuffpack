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
	bool isPrime = true;

	for (int i = 2; i <= maxFactor; ++i)
	{
		if (toCheck % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime)
	{
		std::cout << "prime" << std::endl;
	}
	else
	{
		std::cout << "not prime" << std::endl;
	}
	return 0;
}
