/**********************************************
	 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/
// http://en.wikipedia.org/wiki/Hazard_%28game%29
#include <iostream>
#include <time.h>
#include <limits>
#include <string>
int rollDice(int numRolls);

int lose(std::string msg);
int win(std::string msg);

int main (int argc, char* argv[])
{
	srand(time(0));

	int shooterMain;
	// go 100 times
	for (int count = 1; count <= 1000; ++count)
	{
	//	std::cin.clear();
	//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		int shooterMain;
//		std::cin >> shooterMain;
		shooterMain = 7;
		int roll = rollDice(2);
		int chance =0;
		//std::cout << count << " (" << roll << ") \n";
		switch (roll) //sooters first roll
		{
			case 2:
			case 3:
				lose("Throws out (lose)!");
				break;
			case 11:
			case 12:
				switch (shooterMain)
				{
					case 5:
					case 9:
						lose("Throws out (lose)");
						break;
					case 6:
					case 8:
						if (roll==11)
						{
							lose("Throws out (lose)");
						}
						else
						{
							win("Nicks");
						}
						break;
					case 7:
						if (roll==11)
						{
							win("nicks");
						}
						else
						{
							lose("Throws out");
						}
						break;
				}
				break;
				default:
					if (roll != shooterMain)
					{
						chance = roll;
						//std::cout << "[" <<count << "] ";
						/* use a do loop b/c we set roll=chance above */
						do
						{
							roll = rollDice(2);
							if (roll == chance)
							{
								win("win by chance");
							}
							else if (roll == shooterMain)
							{
								lose ("lose by main");
								// make sure you only lose up to 3 times
							}
							//std::cout << "[" << roll << "]";
						} while (roll != chance && roll != shooterMain);

						//std::cout << std::endl;
					}
					else
					{
						win("Win!");
					}
		}
	}
	int didWin = win(""); // we start at -1 so don't worry about incrementing counter
	int didLose = lose("");
	std::cout << "Win:" <<didWin<< " " << "Lose: " << didLose << std::endl;
	double chance = (double)didWin/(didWin+didLose);
	double realChance, realDisadvantage;
	switch(shooterMain)
	{
		case 5:
			realChance = 0.492;
			realDisadvantage = 1.52;
			break;
		case 6:
			realChance = 0.488;
			realDisadvantage = 2.34;
			break;
		case 7:
			realChance = 0.493;
			realDisadvantage = 1.41;
			break;
		case 8:
			realChance = 0.488;
			realDisadvantage = 2.34;
			break;
		case 9:
			realChance = 0.492;
			realDisadvantage = 1.52;
			break;
	}
	std::cout << "Your chance of winning was " << chance << "This is " << ((chance<realChance) ? "less" :  (chance>realChance) ? "more" : "equal" ) << " than the real chance " << realChance << "\n";
	std::cout << "Your disadvantage is" << realDisadvantage << std::endl;
	return 0;
}

int rollDice(int numRolls)
{
	int result = 0;
	for (int roll = 0; roll < numRolls; ++roll)
	{
		result += rand() % 6 + 1;
	}
	return result;
}


/* start both of these functions @ -1 b/c we will call them to read the end value */

int lose(std::string msg)
{
	static int loseCounter = -1;
	std::cout << msg << std::endl;
	++loseCounter;
	return loseCounter;
}

int win(std::string msg)
{
	static int winCounter = -1;
	std::cout << msg << std::endl;
	++winCounter;
	return winCounter;
}