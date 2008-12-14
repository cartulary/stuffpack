/*no box*/

//Includes
#include <stdio.h>
#include <iostream>
#include <string>
#include "functions.cpp"
/*
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
*/
#include <ctype.h>

using namespace std;

//prototypes of function
void Hanoi(unsigned int n, char source,char dest,char help);

int main (void)
{
	int n;
	cout << "Please enter an integer" << endl;
	n = getinteger(10);
	if (n == -1)
	{
		cerr << "You have not entered an integer " << endl;
		return 1; //error
	}
	Hanoi(n, 'a','b','c');
	return 0;
}

void Hanoi(unsigned int n, char source,char dest,char help)
{
	if (n==1){printf("Move 1 disk from %c to %c\n",source,dest);}

	else //if n>1
	{
		Hanoi(n-1,source,help,dest);
		printf("Move disk from %c to %c\n", source, dest);
		Hanoi(n-1,help,dest,source);
	}
}
