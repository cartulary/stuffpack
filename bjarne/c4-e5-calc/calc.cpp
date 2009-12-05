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
	// Each of the numbers we will be working with
	double first, second;
	// what operation to perform
	char op;
	// what to displau...
	double result;
	while (1)
	{
		// get the ultra simple expression
		cin>> first >> op >> second;
		// ok - now we decide on a result
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
		// and print it out
		cout << "Result = " << result << "\n";
	}
	return EX_OK;
}
