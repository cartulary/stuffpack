#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 100;
const int max_random_number = 1000;

std::vector <int> combsort11(std::vector <int> toSort);

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
	std::cout << "orig - new - num" << std::endl;
	std::vector<int> sortedList = combsort11(toSort);
	/* go until i is 0 and initialize */
	do
	{
		if ( toSort[i] = sortedList[i] )
		{
			std::cout << toSort[i] << " - " << i <<  std::endl;
		}
		else
		{
			std::cout << toSort[i] << " " << sortedList[i] << " " << i <<  std::endl;
		}
	} while (i--);
	std::cout << "orig - new - num" << std::endl;

	return 0;
}

std::vector <int> combsort11(std::vector <int> toSort)
{
	int gap = toSort.size();
	int swaps = -1;
	while (gap > 1 && swaps != 0) 
	{
		if (gap > 1)
		{
			gap = gap / 1.3;
			if (gap == 10 || gap == 9)
			{
				gap = 11;
			}
		}

		swaps = 0;
		for (int i = 0; (i + gap) < toSort.size(); ++i)
		{
			if (toSort.at(i) > toSort.at( i + gap ))
			{
				std::swap ( toSort[i], toSort [ i + gap ] );
				swaps = 1;
			}
		}
	}
	return toSort;
}

