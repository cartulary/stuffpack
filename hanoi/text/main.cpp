//Includes
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

#include "functions.cpp"
#include "../hanoi.cpp"

int main (int argc, char *argv[])
{
	long n = 0; //The amount of blocks.
	/* If the amount of blocks was passed through a command line argument use it: */
	if (argc > 1)
	{
		n = strtol(argv[1],NULL,10); //Extract the # of blocks from CLI arguments and assign it to n.
		/* If n has an incorrect value, ask the user to input a correct one: */
	}
	/* If no number of blocks was passed via command line, ask the user to input a number: */
	else
	{
		n = getinteger(10);
	}
	while (n <= 0)
	{
		cerr << "Please enter a valid integer" << endl;
		n = getinteger(10);
	}

	Hanoi(n, 'a','b','c');
	return 0;
}
