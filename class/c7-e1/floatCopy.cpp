/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes: Write a function which that copies  *
 *	one float array into another.		    *
 *********************************************/

#include <iostream>
#include <sysexits.h>

void floatCopy(float ary1[], float ary2[], int size);

int main (int argc, char* argv[])
{
	const int magic=4;
	float a[magic]={0};
	float b[magic]={1,2,3,magic};
	int s;
	for (s=0;s<magic; ++s)
	{
		std::cout << b[s];
	}
	floatCopy(a,b,magic);
	for (s=0;s<magic; ++s)
	{
		std::cout << b[s];
	}

	return EX_OK;
}

void floatCopy(float ary1[], float ary2[], int size)
{
	int s;
	for (s=0; s < size; ++s)
	{
		ary2[s] = ary1[s];
	}
}
