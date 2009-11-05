/**********************************************
 * Name:                                      *
 * Purpose: 					    *
 * Returns: 	                            *
 * Parameters: 					    *
 * Known bugs:					    *
 * compatibility:					    *
 * notes:						    *
 *********************************************/

#include <iostream>
#include <time.h>
#include <limits>
int rollDice(int numRolls);

int main (int argc, char* argv[])
{
	srand(time(0));

	int winCounter=0;
	int loseCounter=0;
	for (int count = 0; count <= 10000; ++count)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		int shooterMain;
		std::cin >> shooterMain;
		int roll = rollDice(2);
		int chance =0;
		switch (roll) //sooters first roll
		{
			case 2:
			case 3:
				std::cout << "Throws out (lose)!" << std::endl;
				++loseCounter;
				break;
			case 11:
			case 12:
				switch (shooterMain)
				{
					case 5:
					case 9:
						std::cout << "Throws out (lose)" << std::endl;
						++loseCounter;
						break;
					case 6:
					case 8:
						if (roll==11)
						{
							std::cout << "Throws out (lose)" << std::endl;
							++loseCounter;
						}
						else
						{
							std::cout << "Nicks" << std::endl;
							++winCounter;
						}
						break;
					case 7:
						if (roll==11)
						{
							std::cout << "Nicks" << std::endl;
							++winCounter;
						}
						else
						{
							std::cout << "Throws out (lose)" << std::endl;
							++winCounter;
						}
						break;
				}
				break;
				default:
					if (roll != shooterMain)
					{
						chance = roll;
						while (roll != chance && roll != shooterMain)
						{
							roll = rollDice(2);
							if (roll == chance)
							{
								std::cout <<"win by chance" << std::endl;
								++winCounter;
							}
							else
							{
								std::cout << "lose by main" << std::endl;
								++loseCounter;
								// make sure you only lose up to 3 times
							}
						}
					}
					else
					{
						std::cout << "Win!" << std::endl;
						++winCounter;
					}
		}
	}
	std::cout << "Win:" <<winCounter << "Lose: " << loseCounter;
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
