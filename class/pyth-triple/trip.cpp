#include <iostream>
#include <math.h>
#include "libhello.h"

/*
	TODO: make this DP -> store result of multiplication in array
*/
int main(void)
{
	int a,b,c;
	int counter;
	int tripAmt=0;
	const int num_trips = 20;

	int tripArr[num_trips][3] = {{0},{0},{0}};

	for (c=1; tripAmt < num_trips; ++c)
	{
		for (a=1; a <= 2000; ++a)
		{
			for (counter=0; counter < tripAmt; ++counter)
			{
				/* lets see if we are a duplicate */
				if (a % tripArr[counter][0] == 0)
				{
					/* duplicate found; increase a by one and start over the check */
					++a;
					counter=0;
				}
			}
			for (b=a; b<= 2000; ++b)
			{
				if (isPythTriple(a,b,c))
				{
					std::cout << a << " + "<< b << " = "<< c << "\n\t";
					std::cout << pow(a,2) << " + "<< pow(b,2) << " = "<< pow(c,2) << "\n";
					tripArr[tripAmt][0] = a;
					tripArr[tripAmt][1] = b;
					tripArr[tripAmt][2] = c;
					++tripAmt;
				}
			}
		}
	}
	return 0;
}
