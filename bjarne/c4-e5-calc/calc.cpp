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
double term();
// deals with numbers and () (pri 0); uses expression() and get_token();
double primary();

int main (int argc, char* argv[])
{
	try
	{
		while (cin)
		{
			cout << "RESULT ="<<expression();
		}
	}
	catch (exception e)
	{
		cerr << e.what() << "\n";
	}
	catch (...)
	{
		cerr << "Housten we got cheese!\n";
	}
	return EX_OK;
}

double expression()
{
	// infinite recursion
	double left = term();
	Token t = get_token();
	switch (t.kind)
	{
		case '+':
			left += term();
			t = get_token();
			break;
		case '-':
			left -= term();
			t = get_token();
			break;
		default:
			0;
			//we do nothing... let our calling function deal with that
	}
	cout << "(expr) L = " << left <<" O = " << "\n";
	return left;
}

double term()
{
	cout << "(term)\n";
	double left = primary();
	Token t = get_token();
	while (true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary();
				t = get_token();
				break;
			case '/':
				left /= primary();
				t = get_token();
				break;
			//case '%':
			default:
				return left;
		}
	}
	return primary();
}

Token get_token()
{
	char ch;
	cin >> ch;
	if (ch >= '0' && ch <= '9' || '.' == ch)
	{
		double val;
		cin >> val;
		return Token('#',val);
	}
	else
	{
		switch (ch)
		{
			case '(': case ')': case '+': case '-': case '*': case '/': case '%':
				return Token(ch);
				break;
			default:
				err(EX_DATAERR, "%s", "Bad token");
		}
	}
	double rvalue;
	char op;
	cin >> rvalue;
	cin >> op;
	Token t(op, rvalue);
	cout << "(get_tkn) O = " << op <<" R = " << rvalue <<"\n";
	return t;
}

double primary()
{
	Token t = get_token();
	double result;
	switch (t.kind)
	{
		case '#':
			result =  t.value;
			break;
		case '(':
			result = expression();
			t = get_token();
			if (t.kind != ')')
			{
				err(EX_DATAERR, "%s", "Missing )");
			}
			break;
		default:
			result = 0;
			break;
	}
	cout << "(prim) T.v= " << t.value << " T.k = " << t.kind << "\n";
	return result;
}
