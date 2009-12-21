/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes: Write a function to append one      *
 * string to the end of a second string.      *
 *********************************************/

#include <iostream>
#include <sysexits.h>

char* strcat(const char* a, const char* b);

int main (int argc, char* argv[])
{
	const char* foo="daddy";
	const char* boo="longlegs";
	std::cout << strcat(foo,boo);
	return EX_OK;
}

char* strcat(const char* a, const char* b)
{
	int a_len = strlen(a);
	int b_len = strlen(b);
	char* result = new char[a_len+b_len+1];
	int place=0;
	for(;place<a_len;++place)
	{
		result[place]=a[place];
	}
	// place == location in second string;
	int str_start = place;
	for (place=0; place< b_len; ++place)
	{
		result[str_start+place] = b[place];
	}
	result[a_len+b_len+1]=0;
	return result;
}