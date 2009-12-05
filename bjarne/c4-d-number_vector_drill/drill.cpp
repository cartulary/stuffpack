/**********************************************
 * Name: drill                                *
 * Returns: 0 always                          *
 *********************************************/

#include <iostream>
#include <sysexits.h>
#include <iomanip>

using namespace std;

int main (int argc, char* argv[])
{
	double num1;
	double num2;
	double lowest;
	double highest;
	cin >> lowest >> highest;
	while (1)
	{
		cin >> num1 >> num2;
		lowest = (num1 < lowest) ? num1 : lowest;
		highest = (num1 > highest) ? num1 : highest;
		if (num2 < num1)
		{
			swap(num1, num2);
		}
		if (num1==num2)
		{
			cout << "They are exactly equal";
		}
		else if ((num2 - num1) < (1.0/10000000))
		{
			cout << "The number are almost equal\n";
		}
		cout << "The smaller value is: " << num1 << "\nThe larger value is: " << num2;
		cout << "\n";
	}
	return EX_OK;
}
