/**********************************************
 * Name:                                      *
 * Purpose: Act as a simple 4-function calc   *
 * Returns: 0 always                          *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes: This will be improved as I go thru  *
 *		the book				    *
 *********************************************/

#include <iostream>
#include <sysexits.h>

using namespace std;

int main (int argc, char* argv[])
{
	double first, second;
	char op;
	double result;
	while (1)
	{
		cin>> first >> op >> second;
		switch (op)
		{
			case '+':
				result = first + second;
				break;
			case '-':
				result = first - second;
				break;
			case '*':
				result = first * second;
				break;
			case '/':
				result = first / second;
				break;
		}
		cout << "Result = " << result << "\n";
	}
	return EX_OK;
}
