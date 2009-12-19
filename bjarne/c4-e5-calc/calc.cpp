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

/*
	Slight bug: due to term() requiring an '=' sign for each time it is called the following odd syntax is required
	2 * 2 = =
	Due to expression() also requiring an equal sign the current syntax is
	2 * 2 = = =
	//Final number getting cut off --> term() eats last primary
*/

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
			double t = term();
			cout << "RESULT =" << t << '\n';
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
	cout << "(expr) L = " << left <<"\n";
	return left;
}

double term()
{
	double left = primary();
	Token t = get_token();
	while (true)
	{
		switch (t.kind)
		{
			case '*':
				left *= term();
				break;
			case '/':
				left /= term();
				break;
			//case '%':
			default:
				cout << "\n";
				return left;
		}
		t = get_token();
		cout << "(term) left: " << left;
	}
	cout << "\n";
	return left;
}

Token get_token()
{
	char ch;
	cin >> ch;
	if (ch >= '0' && ch <= '9' || '.' == ch)
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('#',val);
	}
	else
	{
		switch (ch)
		{
			case '(': case ')': case '+': case '-': case '*': case '/': case '%': case '=':
				return Token(ch);
				break;
			default:
				//This might have to be warnx
				errx(EX_DATAERR, "%s", "Bad token");
		}
	}
	double rvalue;
	char op;
	cin >> rvalue;
	cin >> op;
	Token t(op, rvalue);
//	cout << "(get_tkn) O = " << op <<" R = " << rvalue <<"\n";
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
			result = term();
			t = get_token();
			if (t.kind != ')')
			{
				errx(EX_DATAERR, "%s", "Missing )");
			}
			break;
		default:
			result = 0;
			break;
	}
//	cout << "(prim) T.k= " << t.kind << " T.v = " << t.value << "\n";
	return result;
}
