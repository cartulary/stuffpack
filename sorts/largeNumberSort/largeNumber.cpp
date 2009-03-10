#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 10;
const int max_random_number = 1000;

std::vector <int> largeNumberSort(std::vector <int> toSort);

int main (void)
{
	std::vector<int> toSort (number_random_objects);

	int i = number_random_objects - 1;
	/* go until i is 0 and initialize */
	do
	{
		toSort[i] = arc4random() % max_random_number;
	} while (i--);

	i = number_random_objects - 1;
	/* go until i is 0 and initialize */
	do
	{
		std::cout << largeNumberSort(toSort)[i] << " " << i <<  std::endl;
	} while (i--);

	return 0;
}

std::vector <int> largeNumberSort(std::vector <int> toSort)
{
	int len = toSort.size();
	std::vector <int> sorted_list(len);
	int capValue = 9999999;
	int largeValue;
	for (int iterations = 0; iterations <= len;  ++iterations)
	{
		/* initialize largeValue */
		largeValue = toSort[0];
		for (int i = 0; i < len; ++i)
		{
//			std::cout << "In inner for: cap/iterations/largeValue/i is " << capValue << " " << iterations << " " << largeValue << " " << i << std::endl;
			if (toSort[i] > largeValue && (toSort[i] < capValue) )
			{
				largeValue = toSort[i];
			}
		}
		/* set the current item in the sort; and the cap to the "large value" */
		capValue = largeValue;
		sorted_list[iterations] = largeValue;
	}
	return sorted_list;
}

