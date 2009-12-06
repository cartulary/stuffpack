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
#include <err.h>

using namespace std;

int main (int argc, char* argv[])
{
	// Each of the numbers we will be working with
	double lval =0;
	double rval;
	// what operation to perform
	char op;

	cin >> lval;
	if (!cin)
	{
		errx(EX_NOINPUT,"%s","You didn't enter any data");
	}
	// as long as we still have an operator continue to do stuff
	while (cin >> op)
	{
		// get the ultra simple expression
		cin >> rval;
		if (!cin)
		{
			errx(EX_NOINPUT,"%s", "You didn't enter an rvalue");
		}
		// ok - now we decide on a result
		switch (op)
		{
			case '+':
				lval += rval;
				break;
			case '-':
				lval -= rval;
				break;
			case '*':
				lval *= rval;
				break;
			case '/':
				lval /= rval;
				break;
			default:
				cout << "Result = " << lval << "\n";
				return EX_OK;
		}
	}
	return EX_OK;
}
