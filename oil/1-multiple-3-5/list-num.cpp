/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/
#include <iostream>

int main (void)
{
	int sum = 0;
	int count = 1000;
	while (--count)
	{
		if (count % 3 == 0 || count % 5 == 0)
		{
			sum += count;
		}
	}
	std::cout << sum;
	return 0;
}
