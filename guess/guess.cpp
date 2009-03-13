#include <stdbool.h>
#include <ctime>
#include <getopt.h>
#include <iostream>
#include <limits.h>
#include <string.h>

#define POSIX

const int NUMBER_BASE = 10;

const int PLAYER_ALL_HUMAN = 1;
const int PLAYER_HUMAN_GUESS = 2;
const int PLAYER_COMP_GUESS = 3;

const int MODE_HIGHLOW = 1;
const int MODE_NO_HINTS = 2;

const int INTERFACE_TEXT = 1;
const int INTERFACE_GRAPHICS = 2;
const int INTERFACE_CURSES = 3;

void usage(char *call_as_name);
char* getcharcters(int max);
long int getInteger(int base, int input_mode);
inline long int getIntInRange(int base, int input_mode, long int min, long int max);
/* make these functions because I want to add networking functionality eventually */
void setAnswer(int num);
inline int checkAnswer(int num); //returns -1 1 or 0 for lower, higher, correct
long int to_guess;

int flagPlayerMode = 0; //computer or human
int flagGameMode = MODE_HIGHLOW; // high-low or pure guess
int flagInterfaceMode = INTERFACE_TEXT;
int flag_verbose = false;

int main(int argc, char* argv[])
{
      int c;
      int option_index = 0;
	while ( true )
	{
      	static struct option long_options[] =
      	{
		/* These options set a flag. */
	            {"p2p",   	      no_argument,      &flagPlayerMode,    PLAYER_ALL_HUMAN},
      	      {"p2c",       	no_argument,      &flagPlayerMode,    PLAYER_HUMAN_GUESS},
            	{"c2p",       	no_argument,      &flagPlayerMode, 	  PLAYER_COMP_GUESS},
	            {"highlow",       no_argument,      &flagGameMode, 	  MODE_HIGHLOW},
      	      {"justguess",     no_argument,      &flagGameMode, 	  MODE_NO_HINTS},
            	{"text",    	no_argument,      &flagInterfaceMode, INTERFACE_TEXT},
	            {"graphics",      no_argument,      &flagInterfaceMode, INTERFACE_GRAPHICS},
      	      {"curses",        no_argument,      &flagInterfaceMode, INTERFACE_CURSES},
			{"verbose", 	no_argument,	&flag_verbose,	  true},
	            {0, 0, 0, 0}
	      };

	      /* getopt_long stores the option index here. */
      	c = getopt_long_only (argc, argv, "", long_options, &option_index);
		if (c == -1)
		{
            	break;
		}
		switch (c)
		{
			default:
				break;
		}
		if (flag_verbose == true)
            {
                  std::cout << "option" << long_options[option_index].name;
                  if (optarg)
                  {
                        std::cout << " with arg " << optarg;
                  }
                  std::cout << std::endl;
            }

	}


	/* initialize the number to -1 */
	long int max = -1;
	/* Ask for the maximum number to use and get it */
	/*
	std::cout << "What number would you like to use as the maximum" << std::endl;
	do
	{
		max = getInteger(NUMBER_BASE);
	} while (max < 1);
	*/

	switch (flagPlayerMode)
	{
		case PLAYER_ALL_HUMAN:
		{
			std::cout << "Player 1 - pick a number:";
			setAnswer ( getInteger ( 10, flagInterfaceMode ) );
			int guessed;
			std::string instructions;
			screen_clear();
			std::cout << "Player 1 - Do you wish to provide any instructions to the other player?  Press enter when your done" << std::endl;
			std::cin >> instructions;
			std::cout << instructions;
			int is_correct;
			do
			{
				std::cout << "Player 2 - Input a number" << std::endl;
				guessed = getInteger(10,flagInterfaceMode);
				is_correct = checkAnswer(guessed);
				/* we are going to check for high-low here and count guesses here; move to new function for eventual networking functionality */
				if (flagGameMode == MODE_HIGHLOW)
				{
					std::string highlow_string;

					if ( is_correct == 1)
					{
						highlow_string = "higher";
					}
					else if ( is_correct == -1 )
					{
						highlow_string = "lower";
					}
					std::cout << highlow_string << std::endl;
				}
			} while (is_correct != 0);
			std::cout << "Your done!" << std::endl;
			break;
		}
		case PLAYER_HUMAN_GUESS:
		{
			/* we add 1 to make the number human appropriate */
			to_guess = arc4random() % (max +1) ;
			break;
		}
		case PLAYER_COMP_GUESS:
		{
			std::cout << "lets play the computer guessing game" << std::endl;
			std::cout << "Please enter the number you wish to use:" << std::endl;
			setAnswer( getIntInRange(NUMBER_BASE, flagInterfaceMode, 0, LONG_MAX) );
			/* let set the min and max to impossible numbers so that we could be sure they are invalid
				for the do loop later */
			std::cout << "What is the least number the computer could guess" << std::endl;
			int comp_guess_min = getIntInRange(NUMBER_BASE, flagInterfaceMode, 0, to_guess - 1);
			std::cout << "What is the highest number the computer could guess" << std::endl;
			int comp_guess_max = getIntInRange(NUMBER_BASE, flagInterfaceMode, to_guess + 1, LONG_MAX);
			break;
		}
      	default:
			std::cout << flagPlayerMode << std::endl;
			usage(argv[0]);
			break;
	}

}

/* this function should perform sanity checking for networking mode */
void setAnswer (int num)
{
	to_guess = num;
}

/*
	Return -1 for less; 1 for more and 0 for equals
*/
inline int checkAnswer (int num)
{
	if ( num < to_guess )
	{
		return -1;
	}
	else if ( num > to_guess )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* continues to call getInteger until number is within range */
inline long int getIntInRange(int base, int input_mode, long int min, long int max)
{
	long int to_return = min - 1 ;
	do
	{
		to_return = getInteger(base, input_mode);
	} while (to_return <= min && to_return >= max);
	return to_return;
}

/*
 Retrieves a integer from the user.
1 == text
2 == graphics
3 == curses
*/
long int getInteger(int base, int input_mode)
{
      int n;
	switch (input_mode)
	{
		case 1:
			n = strtol(getcharcters(10),NULL,base);
			break;
		default:
			break;
	}
      return n;
}

/* Retrieves character input from the user, up to the specified maximum quantity. */
char* getcharcters(int max)
{
      char* str = (char*)malloc(max*sizeof(int)+1);
      char ch;
      int i = 0;

      while ((ch = getchar()) != '\n' && i < max)
      {
            str[i] = ch;
            i++;
      }
      /* I hope this is the right way to terminate a char array. */
      str[max] = NULL;
      return str;
}

/* call_as_name should be argv[0] */
void usage(char* call_as_name)
{
	std::cout << call_as_name << " " << "--interface --playerMode [--verbose]" << std::endl;
	std::cout << "Interfaces: text, graphics, curses" << std::endl;
}

void screen_clear()
{
	//This should eventually deal with networking mode in some sane manner
	#ifdef POSIX
		std::system ( "clear" );
	#else
		#ifdef WINDOWS
			std::system ( "CLS" );
		#else
			//This isn't portable - can we have more code?
		#endif
	#endif

}
