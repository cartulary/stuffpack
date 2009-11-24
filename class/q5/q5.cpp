#include <iostream>

void printElements(int arr[], int size, int div);

int main (int argc, char* argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	printElements(arr, 10, 2);
	std::cout << std::endl;
	return 0;
}

void printElements(int arr[], int size, int div)
{
	int i;
	for (i=0; i < size; ++i)
	{
		if (arr[i] % div == 0)
		{
			std::cout << arr[i] << " ";
		}
	}
}
