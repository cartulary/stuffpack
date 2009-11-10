#include <iostream>

int fact(int num);

int main(void)
{
	std::cout << fact(5) << std::endl;
	return 0;
}

int fact(int num)
{
	if (0 == num)
	{
		return 1;
	}
	return (num * fact(num-1));
}
