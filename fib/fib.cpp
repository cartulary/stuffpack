// I am aware this is broken ->  I wrote this for someone else to fix..
#include <iostream>
int main (void)
{
	double first_num=0;
	double next_num=1;
	double tmp;
	double sum = 0;
	int i;
	for (i = 1; i <= 998; ++i)
	{
		tmp = first_num;
		first_num = next_num;
		next_num = first_num + tmp;
		//sum += first_num;
	}
	std::cout.precision(0);
	std::cout << std::fixed << first_num << std::endl;

	return 0;
}
