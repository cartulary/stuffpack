#include <iostream>

template <typename arrType>
bool arrCmp(arrType a1[], arrType a2[], int size);

int main(void)
{
	int a1[] = {1,2,3};
	int a2[] = {1,2,3};
	std::cout << ((arrCmp(a1,a2,3)==0) ? "false":"true")  << "\n";

	char b1[] = {'d','D','e'};
	char b2[] = {'d','D','e'};
	std::cout << ((arrCmp(b1,b2,3)==0) ? "false":"true")  << "\n";

	int c1[] = {1,2,3};
	int c2[] = {1,2,4};
	std::cout << ((arrCmp(c1,c2,3)==0) ? "false":"true")  << "\n";

	char d1[] = {'d','D','e'};
	char d2[] = {'d','D','E'};
	std::cout << ((arrCmp(d1,d2,3)==0) ? "false":"true")  << "\n";
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

void foo (arrType a)
{}