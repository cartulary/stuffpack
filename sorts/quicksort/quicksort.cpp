#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 20;
const int max_random_number = 1000;

template <typename sortReturnType>
sortReturnType quickSort(sortReturnType toSort);

template <typename sortReturnType>
sortReturnType quickSort_helper(sortReturnType& toSort, int left, int right);

template <typename sortReturnType>
int partition(sortReturnType& toSort, int left, int right, int pivot);

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
	sorted_list = quickSort(toSort);
	/* go until i is 0 and initialize */
	do
	{
		std::cout << sorted_list[i] << " " << i <<  std::endl;
	} while (i--);

	return 0;
}

template <typename sortReturnType>
sortReturnType quickSort(sortReturnType toSort)
{
	return quickSort_helper(toSort, 0, toSort.size() -1);
}


template <typename sortReturnType>
int partition(sortReturnType& toSort, int left, int right, int pivot)
{
	int pivotVal = toSort[pivot];
	std::swap(toSort[pivot],toSort[right]);
	int storeIndex = left;
	int i=left;
	for (; i < right; ++i)
	{
		if (toSort[i] < pivotVal)
		{
			std::swap(toSort[i], toSort[storeIndex]);
			++storeIndex;
		}
	}
	std::swap(toSort[storeIndex], toSort[right]);
	return storeIndex;
}

template <typename sortReturnType>
sortReturnType quickSort_helper(sortReturnType& toSort, int left, int right)
{
	if (right > left)
	{
		int pivot = (left+right)/2;
		int newPivot = partition(toSort, left, right, pivot);
		quickSort_helper(toSort, left,  newPivot -1);
		quickSort_helper(toSort, newPivot + 1, right);
	}

	return toSort;
}
