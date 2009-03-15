#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 150;
const int max_random_number = 1000;

template <typename sortReturnType>
sortReturnType selectionSort(sortReturnType toSort);

int main (void)
{
	std::vector<int> toSort (number_random_objects);
	std::vector<int> sorted_list(number_random_objects);

	int i = number_random_objects - 1;
	/* go until i is 0 and initialize */
	do
	{
		toSort[i] = arc4random() % max_random_number;
	} while (i--);

	i = number_random_objects - 1;
	sorted_list = selectionSort(toSort);
	/* go until i is 0 and initialize */
	do
	{
		std::cout << sorted_list[i] << " " << i <<  std::endl;
	} while (i--);

	return 0;
}

template <typename sortReturnType>
sortReturnType selectionSort(sortReturnType toSort)
{
	int len = toSort.size();
	int min;
	for (int i = 0; i <= len - 2; ++i)
	{
		min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (toSort[j] < toSort[min])
			{
				min = j;
			}
			std::swap ( toSort[i], toSort[min] );
		}
	}
	return toSort;
}

