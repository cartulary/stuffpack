//Includes
#include <stdio.h>
#include <string>
#include "functions.cpp"
#include <ctype.h>

//definitions

//prototypes of function
void Hanoi(unsigned int n, char source,char dest,char help);

int main (void)
{
	unsigned int n;
	n= cGetinteger(10);
	Hanoi(n, 'a','b','c');
	return 0;
}

void Hanoi(unsigned int n, char source,char dest,char help)
{
	if (n==1){printf("Move 1 disk from %c to %c\n",source,dest);}

	else //if n>1
	{
		Hanoi(n-1,source,help,dest);
		printf("Move 1 disk from %c to %c\n", source, dest);
		Hanoi(n-1,help,dest,source);
	}
}
