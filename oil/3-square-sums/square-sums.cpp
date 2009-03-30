#include <iostream>
#include <math.h>
#include <stdio>

int main (void)
{
	unsigned long ing sqaures = 0;
	unsigned long int sum = 0;
	for (int i = 0; i <= 100; ++i)
	{
		sqaures += pow(i,2);
		sum += i;
	}
	std::cout << sqaures <<  " "  << pow(sum,2) << " " << pow(sum,2) - sqaures;
 	printf("%ld\n",(unsigned long int)(pow(sum,2) - sqaures));
	return 0;
}
