#include "libhello.h"
#include "math.h"

bool isPrime(long num)
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
