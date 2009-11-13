/**********************************************
 * Name: Fibonacci number generation          *
 * Returns: 1 on error                        *
 * Parameters: argv[1] is number to compute   *
 * Known bugs: None				    *
 *********************************************/

#include <iostream>
#include <gmp.h>
#include <gmpxx.h>

mpz_class getFibN(long nthFib);

int main (int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cerr << "Please enter a number as argv[1]" << std::endl;
		//die - no number
		return 1;
	}
	/* we a number so lets use it */
	long nthFib = strtol(argv[1], NULL, 10);
	std::cout << getFibN(nthFib) << std::endl;

	return 0;
}

mpz_class getFibN(long nthFib)
{
	// since we want to deal with the users idea of numbers ignore fibMap[0]
	mpz_class *fibMap = new mpz_class[nthFib + 1];

	int i;
	//Mathematiclly we start at 0...
	fibMap[0] = 0; // error - this should never be used
	fibMap[1] = 1;
	for (i = 2; i <= nthFib; ++i)
	{
		fibMap[i] = fibMap[i - 1] + fibMap[i - 2];
	}
	mpz_class result = fibMap[nthFib];
	delete[] fibMap;
	fibMap = NULL;
	return result;

}
