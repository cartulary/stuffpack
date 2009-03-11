#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

const int number_random_objects = 150;
const int max_random_number = 1000;

std::vector <int> shellSort(std::vector <int> toSort);
inline int round (int num);

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
		std::cout << shellSort(toSort)[i] << " " << i <<  std::endl;
	} while (i--);

	return 0;
}

std::vector <int> shellSort(std::vector <int> toSort)
{
	int len = toSort.size();
	int inc = round(len / 2);
	int tmp;
	int j;
	while (inc > 0)
	{
		for (int i = inc; i <= len - 1; ++i)
		{
			tmp = toSort[i];
			j = i;
			while (j >= inc && toSort[j - inc] > tmp)
			{
				toSort[j] = toSort[j - inc];
				j -= inc;
			}
			toSort[j] = tmp;
		}
		inc /= 2.2;
	}
	return toSort;
}

inline int round (int num)
{
	return (num + 0.5);
}
