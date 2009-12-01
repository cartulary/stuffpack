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
#include <string>

int mycmp(const char* s1, const char* s2);
void doTest(char *s1, char *s2);
void printTest(int good, int my);
void testName(std::string str);

int main (int argc, char* argv[])
{
	//I should replace this with a real unit testing system

	char empty[] = "";
	char test[] = "test";
	char halo[] = "halo";
	char test1[] = "test1";
	testName("strcmp");
	doTest(empty,empty);
	doTest(test,test);
	doTest(test,halo);
	doTest(halo,test);
	doTest(test1,halo);
	doTest(halo,test1);
	doTest(test1,test);
	doTest(test,test1);
	testName("strcmp Non-Var Strings");
	doTest("a", "ab");
	doTest("ab", "a");
	doTest("a", "a");
	doTest("", "");
	return 0;
}

void doTest(char *s1, char *s2)
{
	printTest(strcmp(s1,s2), mycmp(s1,s2));
}

void printTest(int goodVal, int myVal)
{
	static int testID = 0;
	++testID;
	std::cout << testID << " Real = " << goodVal << " My = " << myVal << ((goodVal==myVal) ? "" : " failed") << "\n";
}

void testName(std::string str)
{
	std::cout << "=== " << str << "===\n";
}


int mycmp(const char* s1, const char* s2)
{
	int pos;
	for (pos = 0; *(s1 + pos) != '\0' || *(s2 + pos) != '\0'; ++pos)
	{
		if (*(s1 +pos) != *(s2 + pos))
		{
			return *(s1 + pos) - *(s2 + pos);
		}
	}
	// we got to the end of a string and they are so far equal
	return 0;
}