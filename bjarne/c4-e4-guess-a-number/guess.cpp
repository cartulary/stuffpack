/**********************************************
 * Name:                                      *
 * Purpose: Plays guess a number		    *
 * Returns: 0 always                          *
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
	char answer=0;
	const int MAX_TO_TRY = 100;
	int last_guess = MAX_TO_TRY;
	int current_guess = MAX_TO_TRY / 2;
	int max = MAX_TO_TRY;
	int min = 0;
	while (1)
	{
		if (max == min)
		{
			cout << "Your number is " << min << "\n";
			break;
		}
		cout << "(max=" << max << " min=" << min << ")\n";
		cout << "Is your number less than " << current_guess << "? ";
		cin >> answer;
		cout << "\n";
		if (answer=='Y' || answer=='y')
		{
			last_guess = current_guess;
			max = current_guess - 1;
			current_guess = max - ((current_guess - min) / 2);
		}
		else if (answer=='N' || answer=='n')
		{
			last_guess = current_guess;
			min = current_guess;
			current_guess = max - ((max-current_guess) / 2);
		}
	}
	return 0;
}
