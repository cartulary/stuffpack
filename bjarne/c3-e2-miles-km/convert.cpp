/**********************************************
 * Name:                                      *
 * Purpose: Converts between miles and km	    *
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
	const double KmPerMile = 1.609;

	double amount = 0;
	char type = 0;
	cout << "Enter the numbers of miles or kilometers followed by 'm' or 'k'" << endl;
	// continue going until we get a set of valid values
	while (amount == 0 && type == 0)
	{
		cin >> amount >> type;
	}
	// initialize to -1 so we know if we have a problem
	double miles = -1;
	double kilometers = -1;
	switch (type)
	{
		case 'm':
			miles = amount;
			kilometers = miles * KmPerMile;
			break;
		case 'k':
			kilometers = amount;
			miles = kilometers / KmPerMile;
			break;
		default:
			cerr << "Sorry, we can't convert between those values" << endl;
			return EX_DATAERR;
	}
	cout << "Miles = " << miles << '\n';
	cout << "Kilometers = " << kilometers << '\n';
	return EX_OK;
}
