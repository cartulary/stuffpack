#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 20;
const int max_random_number = 1000;

std::vector <int> insertSort(std::vector <int> toSort);

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
		std::cout << insertSort(toSort)[i] << " " << i <<  std::endl;
	} while (i--);

	return 0;
}

std::vector <int> insertSort(std::vector <int> toSort)
{
	int len = toSort.size();
	int val;
	int j;
	for (int i = 1; i <= len - 1; ++i)
	{
		val = toSort[i];
		j = i - 1;
		while ( j >= 0 && toSort[j] > val)
		{
			toSort[j + 1] = toSort[j];
			--j;
		}
		toSort[j+1] = val;
	}
	return toSort;
}

