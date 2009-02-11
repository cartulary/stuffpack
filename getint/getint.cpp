#include <iostream>
#include <limits>

int getInt(int min = std::numeric_limits<int>::min()  , int max = std::numeric_limits<int>::max() );

int main (void)
{
	std::cout << getInt();
	return 0;
}

int getInt(int min, int max)
{
	int num;
   	while (!(std::cin >> num) || num < min || num > max)
   	{
	     	std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   	}
	return num;
}
