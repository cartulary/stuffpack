//Includes
#include <stdio.h>
#include <stdlib.h>

void Hanoi(unsigned int n, const char source, const char dest, const char help);

void Hanoi(unsigned int n, const char source, const char dest, const char help)
{
	if (n==1)
	{
		printf("Move disk from %c to %c\n", source, dest);
	}

	else //if n>1
	{
		Hanoi(n-1,source,help,dest);
		printf("Move disk from %c to %c\n", source, dest);
		Hanoi(n-1,help,dest,source);
	}
}
