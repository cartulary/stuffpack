#include <iostream>
int main (void)
{
	double first_num=0;
	double next_num=1;
	double tmp;
	double sum = 0;
	int i;
	for (int i = 0; i <= 75; ++i)
	{
		tmp = first_num;
		first_num = next_num;
		next_num = first_num + tmp;
		std::cout << std::fixed << first_num << std::endl;
	}
	return 0;
}
