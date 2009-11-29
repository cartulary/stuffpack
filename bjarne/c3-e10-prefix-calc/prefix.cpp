/**********************************************
 * Name:                                      *
 * Purpose: acts as a simple prefix calculator*
 * Returns: 1 on error                        *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/

#include <iostream>
#include <sysexits.h>

using namespace std;

int main (int argc, char* argv[])
{
	double operand[2];
	char operation;
	double result;
	while (1)
	{
		cin >> operation;
		if (operation == 'q')
		{
			break;
		}
		cin >> operand[0] >> operand[1];
		switch (operation)
		{
			case '+':
				result = operand[0] + operand[1];
				break;
			case '-':
				result = operand[0] - operand[1];
				break;
			case '*':
				result = operand[0] * operand[1];
				break;
			case '/':
				result = operand[0] / operand[1];
				break;
			default:
				cerr << "This is not an operation I know\n";
				return EX_DATAERR;
		}
		cout << "Result = " << result << "\n";
	}
	return EX_OK;
}
