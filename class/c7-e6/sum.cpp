#include <iostream>
#include <sysexits.h>

void sum(int* first, int* addIt);

int main (int argc, char* argv[])
{
	int a = 1;
	int b = 2;
	sum(&a,&b);
	std::cout << a << "\n";
	return EX_OK;
}

void sum(int* first, int* addIt)
{
	*first += *addIt;
}
