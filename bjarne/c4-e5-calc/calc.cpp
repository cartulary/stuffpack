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
#include "token.h"

using namespace std;

// Reads characters and composes tokens; use cin
Token get_token();
// deals with + and - (pri 2); uses term() and get_token()
double expression();
// deals with */% (pri 1); uses primary() and get_token()
Token term();
// deals with numbers and () (pri 0); uses expression() and get_token();
double primary();

int main (int argc, char* argv[])
{
	// Each of the numbers we will be working with
	double lval =0;
	double rval;
	// what operation to perform
	char op;

	cout << expression();
	return EX_OK;

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

double expression()
{
	// infinite recursion
	Token l = term();
	Token t = get_token();
	switch (l.kind)
	{
		case '+':
			l.value += term().value;
			break;
		case '-':
			l.value -= t.value;
			break;
		default:
			l.value = t.value;
			//we do nothing... let our calling function deal with that
	}
	cout << "(expr) L = " << l.value <<" O = " << t.kind << " R = " << t.value << "\n";
	return l.value;
}

Token term()
{
	cout << "(term)\n";
	Token t = get_token();
	return t;
}

Token get_token()
{
	double rvalue;
	char op;
	cin >> rvalue;
	cin >> op;
	Token t(op, rvalue);
	cout << "(tkn) O = " << op <<" R = " << rvalue <<"\n";
	return t;
}
