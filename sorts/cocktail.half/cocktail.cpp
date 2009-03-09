#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 150;
const int max_random_number = 1000;

std::vector <int> cocktailSort(std::vector <int> toSort);

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
		std::cout << cocktailSort(toSort)[i] << " " << i <<  std::endl;
	} while (i--);

	return 0;
}

/*
	to do:
	  we should remember where the last swap took place and not go post it
*/
std::vector <int> cocktailSort(std::vector <int> toSort)
{
	bool swapped;
	int len = toSort.size();
	int begin = -1;
	int end = len -1;
	do
	{
		swapped = false;
		++begin;
		for (int i = begin; i <= end; ++i)
		{
			if (toSort[i] > toSort  [ i + 1 ])
			{
				std::swap ( toSort[i], toSort [ i + 1 ] );
				swapped = true;
			}
		}
    		if (swapped == false)
		{
			//nothing has changed; we are done
			std::cout << "test";
			break;
		}
		swapped = false;
		//everything after the new end is in order
		--end;
		//onto the backwords pass
            for (int i = end ; i >= begin ; --i)
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
