//Includes
#include <stdio.h>
#include "functions.c"
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

//prototypes of function
void Hanoi(unsigned int n, char source,char dest,char help);

int main (int argc, char *argv[])
{
	long n;
	/* If the amount was passed through a command line argument use it */
	if (argc > 1)
	{
		n = strtol(argv[1],NULL,10);
	}
	else
	{
		n = getinteger(10);
	}

      if (n <=0)
      {
            printf("Please enter a valid integer\n");
		/* this has to go to std error soon) */
            exit(1);
      }

	//start the program
	Hanoi(n, 'a','b','c');
	return 0;
}

/**********************************************
 * Name:    Hanoi                             *
 * Purpose: run the hanoi algorithm           *
 * Returns: nothing                           *
 * Parameters: number of times to interate;   *
 *  char to use for source/dest/help 	    *
 * Output: steps to complete tower of hanoi   *
 *********************************************/

void Hanoi(unsigned int n, const char source,char dest, const char help)
{
	if (n==1)
	{
		printf("Move disk from %c to %c\n",source,dest);
	}

	else //if n>1
	{
		Hanoi(n-1,source,help,dest);
		printf("Move disk from %c to %c\n", source, dest);
		Hanoi(n-1,help,dest,source);
	}
}
