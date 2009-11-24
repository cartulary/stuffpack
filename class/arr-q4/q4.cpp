#include <iostream>
#include <limits>

int main (int argc, char* argv[])
{
	int num;
	std::cout << "Please enter a number:\n";

	while ( !( std::cin >> num ))
	{
		std::cerr<<"Please enter an integer\n";

		// Discarding the entire line
		std::cin.clear();
		std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
	}

	bool *binary = new bool[num];
	int i;
	int last_one = 0;
	for (i=0; i < 10; ++i)
	{
		binary[i] = num % 2;
		num = (num-binary[i]) / 2;
		if (binary[i] == 1)
		{
			last_one = i;
		}
	}
	for (i=last_one; i >= 0; --i)
	{
		std::cout << binary[i];
	}
	std::cout << std::endl;
	delete[] binary;
	return 0;
}
