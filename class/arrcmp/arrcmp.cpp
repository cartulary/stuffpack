#include <iostream>

template <typename arrType>
bool arrCmp(arrType a1[], arrType a2[], int size);
bool arrCmp(char a1[], char a2[]);

int main(void)
{
	int a1[] = {1,2,3};
	int a2[] = {1,2,3};
	std::cout << "T=" << ((arrCmp(a1,a2,3)) ? "true":"false")  << "\n";

	char b1[] = {'d','D','e'};
	char b2[] = {'d','D','e'};
	std::cout << "T=" <<((arrCmp(b1,b2,3)) ? "true":"false")  << "\n";

	int c1[] = {1,2,3};
	int c2[] = {1,2,4};
	std::cout << "F=" <<((arrCmp(c1,c2,3)) ? "true":"false")  << "\n";

	char d1[] = {'d','D','e'};
	char d2[] = {'d','D','E'};
	std::cout << "F=" <<((arrCmp(d1,d2,3)) ? "true":"false")  << "\n";

	char e1[] = "abc";
	char e2[] = "abc";
	std::cout << "T=" <<((arrCmp(e1,e2)) ? "true":"false")  << "\n";

	char f1[] = "abc";
	char f2[] = "abcd";
	std::cout << "F=" << ((arrCmp(f1,f2)) ? "true":"false")  << "\n";

	char g1[] = "abc";
	char g2[] = "xyz";
	std::cout << "F=" << ((arrCmp(g1,g2)) ? "true":"false")  << "\n";
	return 0;
}

template <typename arrType>
bool arrCmp(arrType a1[], arrType a2[], int size)
{
	int i;
	for (i=0; i < size; ++i)
	{
		if (a1[i] != a2[i])
		{
			return false;
		}
	}
	return true;
}

bool arrCmp(char a1[], char a2[])
{
	int i;
	for (i=0; a1[i]!=NULL || a2[i] != NULL; ++i)
	{
		if (a1[i] != a2[i])
		{
			return false;
		}
	}

	return (a1[i] == a2[i]);
}
