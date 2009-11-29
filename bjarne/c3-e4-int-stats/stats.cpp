/**********************************************
 * Name:                                      *
 * Purpose: Displays info about double and int*
 * Returns: 0 always                          *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/

#include <iostream>
#include <sysexits.h>
#include <iomanip>

using namespace std;

int main (int argc, char* argv[])
{
	double num1;
	double num2;
	cout << "Enter two numbers\n";
	cin >> num1 >> num2;
	int int1 = static_cast<int>(num1);
	int int2 = static_cast<int>(num2);
	cout << "small,large,sum,diff,product,ratio\n";
	cout << std::setw(7) << "small " << ((num1 < num2) ? num1 : num2) << "" << '\n';
	cout << std::setw(7) << "large " << ((num1 > num2) ? num1 : num2) << "" << '\n';
	cout << std::setw(7) << "sum " << num1 + num2 << " "<<int1 + int2 << '\n';
	cout << std::setw(7) << "diff " << num1 - num2 << " "<<int1 - int2 << '\n';
	cout << std::setw(7) << "prod " << num1 * num2 << " "<<int1 * int2 << '\n';
	cout << std::setw(7) << "ratio " << num1 / num2 << " " <<int1 / int2 << '\n';
	return EX_OK;
}
