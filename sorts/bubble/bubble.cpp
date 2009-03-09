#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 150;
const int max_random_number = 1000;

std::vector <int> bubbleSort(std::vector <int> toSort);

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
		std::cout << bubbleSort(toSort)[i] << " " << i <<  std::endl;
	} while (i--);

	return 0;
}

std::vector <int> bubbleSort(std::vector <int> toSort)
{
	bool swapped;
	int len = toSort.size();
	do
	{
		swapped = false;
		len = len - 1;
		for (int i = 0; i <= len - 1; ++i)
		{
			if (toSort[i] < toSort  [ i + 1 ])
			{
				std::swap ( toSort[i], toSort [ i + 1 ] );
				swapped = true;
			}
		}
	} while (swapped);
	return toSort;
}

