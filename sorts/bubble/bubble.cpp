#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

std::vector <int> bubbleSort(std::vector <int> toSort);

int main (void)
{
	std::vector<int> toSort (150);

	int i = 149;
	/* go until i is 0 and initialize */
	do
	{
		toSort[i] = arc4random() % 1000;
	} while (i--);

	i = 149;
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
		for (int i = 0; i <= len - 2; ++i)
		{
			if (toSort[i] > toSort  [ i + 1 ])
			{
				std::swap ( toSort[i], toSort [ i + 1 ] );
				swapped = true;
			}
		}
	} while (swapped);
	return toSort;
}

