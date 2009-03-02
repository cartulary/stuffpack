#include <stdbool.h>
#include <ctime>
#include <getopt.h>
#include <iostream>

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
long int getInteger(int base);

int flagPlayerMode = 0; //computer or human
int flagGameMode = 0; // high-low or pure guess
int flagInterfaceMode = INTERFACE_TEXT;
int flag_verbose = false;

int main(int argc, char* argv[])
{
      int c;
      int option_index = 0;
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
      c = getopt_long (argc, argv, "", long_options, &option_index);

	/* initialize the number to -1 */
	long int max = -1;
	/* Ask for the maximum number to use and get it */
	std::cout << "What number would you like to use as the maximum" << std::endl;
	do
	{
		max = getInteger(NUMBER_BASE);
	} while (max < 1);
	long int to_guess; // this is the number that has to be guessed
	switch (flagPlayerMode)
	{
		case PLAYER_ALL_HUMAN:
			std::cout << "Player 1 - pick a number:";
			to_guess = getInteger(10);
			break;
		case PLAYER_HUMAN_GUESS:
			/* we add 1 to make the number human appropriate */
			to_guess = arc4random() % (max +1) ;
			break;
		case PLAYER_COMP_GUESS:
			break;
      	default:
			usage(argv[0]);
			break;
	}
}


/* Retrieves a integer from the user. */
long int getInteger(int base)
{
      int n = 0;

      n = strtol(getcharcters(10),NULL,base);

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
	std::cout << call_as_name << " " << "hello!" << std::endl;
}
