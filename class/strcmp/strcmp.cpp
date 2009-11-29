/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/

#include <iostream>
#include <math.h>

int mycmp(char* s1, char* s2);
void doTest(char *s1, char *s2);

int main (int argc, char* argv[])
{
	//I should replace this with a real unit testing system

	char empty[] = "";
	char test[] = "test";
	char halo[] = "halo";
	char test1[] = "test1";
	doTest(empty,empty);
	doTest(test,test);
	doTest(test,halo);
	doTest(halo,test);
	doTest(test1,halo);
	doTest(halo,test1);
	doTest(test1,test);
	doTest(test,test1);

	return 0;
}

void doTest(char *s1, char *s2)
{
	static int testID = 0;
	++testID;
	int goodVal = strcmp(s1,s2);
	int myVal = mycmp(s1,s2);
	char failed = 'Y';
	if (goodVal == myVal)
	{
		failed = 'N';
	}
	std::cout << testID << " Real = " << goodVal << " My = " << myVal << " failed = "<< failed << "\n";
}

int mycmp(char* s1, char* s2)
{
	int pos;
	for (pos = 0; s1[pos] != '\0' && s2[pos] != '\0'; ++pos)
	{
		if (s1[pos] != s2[pos])
		{
			return s1[pos] - s2[pos];
		}
	}
	// we got to the end of a string and they are so far equal
	return s1[pos] - s2[pos];
}
