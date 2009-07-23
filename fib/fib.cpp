#include <iostream>
int main (void)
{
	double first_num=0;
	double next_num=1;
	double tmp;
	double sum = 0;
	int i;
	for (i = 1; i <= 75; ++i)
	{
		tmp = first_num;
		first_num = next_num;
		next_num = first_num + tmp;
		sum += first_num;
		std::cout << std::fixed << first_num << "(" << i << ")" <<std::endl;
	}
	std::cout << std::fixed << sum << std::endl;
	return 0;
}
