/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes: Write a function which that copies  *
 *	one null ended char array array into    *
 *	another in reverse order.		    *
 *********************************************/

#include <iostream>
#include <sysexits.h>

void strCopy(char* ary1[], char* ary2[], int size);

int main (int argc, char* argv[])
{
	const int magic=7;
	char* a[]={"hello"};
	char* b[]={"aaaaa"};
	int s;
	std::cout << *b <<"\n";
	strCopy(a,b,magic);
	std::cout << *b;

	return EX_OK;
}

void strCopy(char* ary1[], char* ary2[], int size)
{
	int s;
	for (s=0 ; s < size; ++s)
	{
		ary2[size -1] = ary1[size-s-1];
	}
}
