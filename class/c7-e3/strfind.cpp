/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
XX
 *********************************************/

#include <iostream>
#include <sysexits.h>

char* findChar(char* s, char c);

int main (int argc, char* argv[])
{

	if ( findChar("daddylonglegs",'z') != NULL)
	{
		std::cout << "Found it!!\n";
	}
	return EX_OK;
}

char* findChar(char* s, char c)
{
	int i;
	for(i=0; s[i] != c && s[i] != 0; ++i);
	if (s[i] == c)
	{
		return &s[i];
	}
	return 0;
}
