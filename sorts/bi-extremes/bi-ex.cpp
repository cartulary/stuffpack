#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 20;
const int max_random_number = 1000;

template <typename sortReturnType>
sortReturnType biexSort(sortReturnType toSort);

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
	sorted_list = biexSort(toSort);
	/* go until i is 0 and initialize */
	do
	{
		std::cout << sorted_list[i] << " " << i;
	} while (i--);
	std::cout << std::endl;

	return 0;
}

template <typename sortReturnType>
sortReturnType biexSort(sortReturnType toSort)
{
	int len = toSort.size();
	int last = len - 1;
	int min_position;
	int max_position;
	for (int first = 0; first != (len 1) / 2; ++first)
	{
		std::cout << first << " " << last << std::endl;
		/* this could be any arbitrary element on the list within the first-last range*/
		min_position = first;
		max_position = first;
		for (int j = first; j < last; ++j)
		{
			if (toSort[j] < toSort[min_position])
			{
				min_position = j;
				continue;
			}
			if (toSort[j] > toSort[min_position])
			{
				max_position = j;
				continue;
			}
		}
		std::swap(toSort[first], toSort[min_position]);
		std::swap(toSort[last], toSort[max_position]);
		--last;
	}
	return toSort;
}

