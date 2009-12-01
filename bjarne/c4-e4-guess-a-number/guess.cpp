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

int getNextGuess(int current, int min, int max, bool lessThanCurrent);

using namespace std;

int main (int argc, char* argv[])
{
	char answer=0;
	const int MAX_TO_TRY = 100;
	int last_guess = MAX_TO_TRY;
	int current_guess = MAX_TO_TRY / 2;
	int max = MAX_TO_TRY;
	int min = 0;
	int tries = 0;
	while (1)
	{
		if (max == min)
		{
			cout << "Your number is " << min << " in "<< tries <<" tries!\n";
			break;
		}
		++tries;
		cout << "Is your number less than " << current_guess << "? ";
		cin >> answer;
		cout << "\n";
		bool lessThanCurrent = false;
		last_guess = current_guess;
		if (answer=='Y' || answer=='y')
		{
			lessThanCurrent = true;
			max = current_guess - 1;
		}
		else if (answer=='N' || answer=='n')
		{
			min = current_guess;
		}
		current_guess = getNextGuess(current_guess, min, max, lessThanCurrent);
	}
	return 0;
}

int getNextGuess(int current, int min, int max, bool lessThanCurrent)
{
	if (lessThanCurrent)
	{
		return max - ((current - min) /2);
	}
	else
	{
		return max - ((max - current) / 2);
	}
}
