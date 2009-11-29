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
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct coin
{
	string name;
	double value;
	int amount;
};

int main (int argc, char* argv[])
{
	coin coins[6];
	coins[0].name = "pennie";
	coins[0].value=0.01;
	coins[1].name = "nickel";
	coins[1].value=0.05;
	coins[2].name = "dime";
	coins[2].value=0.10;
	coins[3].name = "quarter";
	coins[3].value=0.25;
	coins[4].name = "half dollar";
	coins[4].value=0.50;
	coins[5].name = "dollar";
	coins[5].value=1.00;
	int i;
	double total = 0;
	for (i=0; i < 6; ++i)
	{
		cout << "How many " << coins[i].name << "s do you have?\n";
		cin >> coins[i].amount;
		total += coins[i].amount * coins[i].value;
	}
	cout << "For a total value of "<<"$"<<setprecision(2) << fixed << total << "\n";
	return EX_OK;
}
