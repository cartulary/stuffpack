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
int myncmp(const char* s1, const char* s2, size_t len);
void doTest(char *s1, char *s2);
void doNTest(char *s1, char *s2, int len);
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

	testName("strncmp");
	doNTest(empty,empty,0);
	doNTest(test,test,0);
	doNTest(test,test,1);
	doNTest(test,test,4);
	doNTest(test,halo,4);
	doNTest(halo,test,4);
	doNTest(test1,halo,4);
	doNTest(test1,halo,5);
	doNTest(halo,test1,4);
	doNTest(halo,test1,5);
	doNTest(test1,test,4);
	doNTest(test,test1,4);
	doNTest(test1,test,5);
	doNTest(test,test1,5);

	return 0;
}

void doTest(char *s1, char *s2)
{
	printTest(strcmp(s1,s2), mycmp(s1,s2));
}

void doNTest(char *s1, char *s2, int len)
{
	printTest(strncmp(s1,s2,len), myncmp(s1,s2, len));
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
	for (pos = 0; s1[pos] != '\0' || s2[pos] != '\0'; ++pos)
	{
		if (s1[pos] != s2[pos])
		{
			return s1[pos] - s2[pos];
		}
	}
	// we got to the end of a string and they are so far equal
	return 0;
}

int myncmp(const char* s1, const char* s2, size_t len)
{
	int pos;
	for (pos = 0; (s1[pos] != '\0' || s2[pos] != '\0') && pos < len; ++pos)
	{
//		std::cerr << "pos=" << pos << "len=" << len << "s1/s2" << s1[pos] << " " << s2[pos] <<"\n";
		if (s1[pos] != s2[pos])
		{
			return s1[pos] - s2[pos];
		}
	}
//	std::cerr << "!pos=" << pos << "len=" << len << "s1/s2" << s1[pos] << " " << s2[pos] <<"\n";
	// we got to the end of a string and they are so far equal
	if (len == pos)
	{
		++pos;
	}
	return 0;
}
