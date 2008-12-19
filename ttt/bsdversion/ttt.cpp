/*
Tik-Tak-Toe CTY Final Project
Version 0.04
*/

#include "ttt.h"

player board[BOARD_SIZE+1][BOARD_SIZE+1]; //a 3x3 board except that the array starts at 0 so it is size+1
player turn=none; //current turn

/* verbose will be 0 (off) or 1 (on)*/
static int flag_verbose = FALSE;
/* difficulty will be 0 (no computer moves allowed) 1 (easy) or 2 (hard)*/
static int flag_difficulty = MODE_EASY;
/* number of players flag */
static int flag_num_players = 1;

using namespace std;

int main (int argc, char* argv[])
{
      int c;
     	int option_index = 0;
	char moveFirst;
      while (1)
      {
      	static struct option long_options[] =
            {
            	/* These options set a flag. */
               	{"brief",   	no_argument,      &flag_verbose, 	FALSE},
              	{"verbose",		no_argument,      &flag_verbose, 	TRUE},
               	{"nocheat", 	no_argument,      &flag_difficulty,	FALSE}, //defaults to true
			{"easy", 		no_argument,	&flag_difficulty,	MODE_EASY},
			{"hard",		no_argument,	&flag_difficulty, MODE_HARD},
               	{"nohuman", 	no_argument,      &flag_num_players,0}, //active
               	{"onehuman",	no_argument,      &flag_num_players,0}, //active
			{"allhuman",	no_argument,	&flag_num_players,2},
              	{0, 0, 0, 0}
            };
           	/* getopt_long stores the option index here. */
    	      c = getopt_long (argc, argv, "", long_options, &option_index);
		if (c == -1)
		{
			break;
		}
		cout << "option %s" << long_options[option_index].name;
           	if (optarg)
		{
           		cout << " with arg " << optarg;
		}
		cout << endl;
	}
	cout << "Welcome to tik-tak-toe with a 'k'" << endl;
	if (flag_num_players > 0)
	{
		/*FIXME: change this to which player moves first on 2 player mode */
		cout << "Do you want to move first? [Y/N] ";
	    	scanf("%c", &moveFirst);
		/* endl after the question */
		cout << endl;
	    	if (moveFirst == 'Y')
		{
      		turn = TURN_PLAYER;
		}
    		else
		{
	      	turn = TURN_COMP;
		}
	}
	else
	{
		/* if there is no player start with X */
		turn = X;
	}

	bool compNow;
	bool cont=true;
	int lastMoveO,lastMoveX;
	do
	{
		/* if there is no open space - stop */
		cont=(openSpace());
		if (cont)
		{
			cout << "Player " << playerToString(turn) << "%c's turn." << endl;
			/* show the board AFTER the move is made */
			displayBoard();
			compNow = FALSE;
			if (flag_num_players == 0)
			{
				compNow = TRUE;
			}
			if (flag_num_players == 1 && turn == TURN_COMP)
			{
				compNow = true;
			}
			if (compNow == TRUE)
			{
				lastMoveX = compMoveMain(lastMoveX, turn);
			}
			else
			{
				lastMoveO = getMove();
			}
			cont = (!checkWin()); // continue if no win
			turn = switchTurn(turn); //change the turn string

		}
	} while (cont);
	if (checkWin())
	{
		turn = switchTurn(turn); //change the turn string back if someone won
		printf("\nPlayer %c won!!!\n", playerToString(turn));
		displayBoard();
	}
	else
	{
		cout << "So you tied... :-(" << endl;
	}
}


void displayBoard(void)
{
	/*TODO: change from printf*/
	player current;
	int count=0;
	cout << endl;
	for (int row=1;row<=3;row++)
	{
		for (int col=1;col<=3;col++)
		{
			count++;
			current = board[row][col];
			printf("   ");
			if (current==none)
			{
				printf("%d",count);
			}
			else
			{
				printf("%c",playerToString(current));
			}
			printf("\t|\t");
		}
		printf("\n--------|---------------|---------------|\n");
	}
	cout << endl;
}
void initBoard(void)
{
	for (int row=0;row<=BOARD_SIZE;row++)
	{
		for (int col=0;col<=BOARD_SIZE;col++)
		{
			board[row][col]=none;
		}
	}
}

int getMove(void)
{
	int move;
	bool cont=true;
	int row, col;
	do
	{
		cont=false; //assume they enter a correct number
		printf("Player %c please enter a number between 1 and 9: ", playerToString(turn));
		move=GetInteger(10);
		row = getRowFromID(move);  //get the row
		col = getColFromID(move);  //get the column
		//check for things that are wrong
		if (move<1||move>9){cont=true;}
		if (move==99)
		{
			if (flag_difficulty != 0)
			{
				cont = false;
				return compMoveMain(NULL,TURN_PLAYER);
			}
			else
			{
				verbosePrint((char*)"Player is not allowed to cheat",1);
			}
		}
		if (board[row][col]!=none){cont=true;} //if there was a move already there then retry
	} while(cont);
	board[row][col]=turn;
	return move;
}

inline char playerToString(player toConvert)
{
	switch (toConvert)
	{
		case X:
			return 'X';
		case O:
			return 'O';
		case none:
			return NULL;
		default:
			/*FIXME:have this return to main instead of exiting here*/
			cerr << "programming error invalid player" <<endl;
			exit(1);
	}
}

inline player stringToPlayer(char toConvert)
{
      switch (toConvert)
      {
            case 'X':
                  return X;
            case 'O':
                  return O;
            case NULL:
                  return none;
            default:
			/*FIXME:have this return to main instead of exiting here*/
                  cerr << "programming error invalid char" <<endl;
                  exit(1);
      }
}

inline player switchTurn(player toSwitch)
{
	switch (toSwitch)
	{
		case O:
			return X;
		case X:
			return O;
            default:
			/*FIXME:have this return to main instead of exiting here*/
                  cerr << "programming error invalid player switch" <<endl;
                  exit(1);
	}
}

inline int getRowFromID(int id)
{
	//from a number between 1 and 9, return the row
	int tmp;
	tmp = ((id/3)+1);
	if (id%3==0){tmp-=1;} //if tmp is divisable by 3 then do not add one to the answer
	return (tmp); //int math - no remainder
}

inline int getColFromID(int id)
{
	//from a number between 1 and 9, return the col
	int tmp;
	tmp=(id%3);
	if (tmp==0) {tmp=3;}
	return (tmp);
}

bool checkWin(void)
{
	/*
	I would check for neignbors, but it involves the smame amount of time due to checking to see what row.col it is
	*/
	//All possable win:
	/*
	1	2	3
	4	5	6
	7	8	9

	1-2-3
	4-5-6
	7-8-9

	1-4-7
	2-5-8
	3-6-9

	1-5-9
	3-5-7
	*/
	bool win=false; //assume not win.
	
	//check all win senarios
	//win by row
	if  (board[1][1]==board[1][2]&&board[1][1]==board[1][3]&&board[1][1]!=none){win=true;} 
	if  (board[2][1]==board[2][2]&&board[2][1]==board[2][3]&&board[2][1]!=none){win=true;} 
	if  (board[3][1]==board[3][2]&&board[3][1]==board[3][3]&&board[3][1]!=none){win=true;} 

	//win by col
	if  (board[1][1]==board[2][1]&&board[1][1]==board[3][1]&&board[1][1]!=none){win=true;} 
	if  (board[1][2]==board[2][2]&&board[1][2]==board[3][2]&&board[1][2]!=none){win=true;} 
	if  (board[1][3]==board[2][3]&&board[1][3]==board[3][3]&&board[1][3]!=none){win=true;} 

	//win by diag.
	if  (board[1][1]==board[2][2]&&board[1][1]==board[3][3]&&board[1][1]!=none){win=true;} 
	if  (board[1][3]==board[2][2]&&board[1][3]==board[3][1]&&board[1][3]!=none){win=true;} 

	return(win);
}

bool openSpace()
{
	for (int row=1;row<=BOARD_SIZE;row++)
	{
		for (int col=1;col<=BOARD_SIZE;col++)
		{
			if (board[row][col]==none){return (true);} //if there is an open space say so
		}
	}
	return (false); //if it completes the loop there is no open space
}

int nextMoveWin(int lastMove, player whoToWin)
{
	int row, col;
	row = getRowFromID(lastMove);
	col = getColFromID(lastMove);
	int emptySpace;

	for (int rowCounter=1;rowCounter<=BOARD_SIZE;rowCounter++)
	{
		if (row!=rowCounter)
		{
			emptySpace = 6-row-rowCounter;
			if (board[row][col]==board[rowCounter][col]&&board[rowCounter][col]!=none) //keep col same.
			{
				if (board[emptySpace][col]==none)
				{
					if (board[row][col]==whoToWin) {return (getID(emptySpace, col));}
				}

			}
		}
	}
	for (int colCounter=1;colCounter<=BOARD_SIZE;colCounter++)
	{
		if (col!=colCounter)
		{
			emptySpace = 6-col-colCounter;
			if (board[row][colCounter]==board[row][col]&&board[row][colCounter]!=none)  //keep row same.
			{
				if (board[row][emptySpace]==none)
				{
					if (board[row][col]==whoToWin) {return (getID(row, emptySpace));}
				}
			}
		}
	}	

	//by now you either won't win or you will win by diag
	bool winDiag=false;

	if (board[1][1]==board[2][2]&&board[3][3]==none&&board[1][1]!=none)
	{
		row = 3;
		col= 3;
		winDiag = true;
	}
	if (board[1][1]==board[3][3]&&board[2][2]==none&&board[1][1]!=none)
	{
		row = 2;
		col= 2;
		winDiag = true;
	}
	if (board[2][2]==board[3][3]&&board[1][1]==none&&board[2][2]!=none)
	{
		row = 1;
		col= 1;
		winDiag = true;
	}


	if (board[1][3]==board[2][2]&&board[3][1]==none&&board[2][2]!=none)
	{
		row = 3;
		col= 1;
		winDiag = true;
	}
	if (board[1][3]==board[3][1]&&board[2][2]==none&&board[1][3]!=none)
	{
		row = 2;
		col= 2;
		winDiag = true;
	}
	if (board[2][2]==board[3][1]&&board[1][3]==none&&board[2][2]!=none)
	{
		row = 1;
		col= 3;
		winDiag = true;
	}

	return (winDiag?getID(row,col):0); //return the ID if you will win by diag, or 0 if no win
}

/* this function returnss the location from a row and col */
inline int getID(int row, int col)
{
	return ((BOARD_SIZE * row) + col - BOARD_SIZE);
}

int compMoveMain(int lastMove, player whoToMove)
{
	int nextMove;
	int row, col;
	nextMove = nextMoveWin(lastMove, whoToMove); //nextMove becomes the number of the next wining spot, 0 if no next move win
	if (nextMove==0) //if not next move win, try different set of moves
	{
		nextMove = compMove(whoToMove);
	}
	row = getRowFromID(nextMove);
	col = getColFromID(nextMove);
	board[row][col]=whoToMove; //set computers move
	return (nextMove);

}
int compMove(player whoToMove)
{
	verbosePrint((char*)"trying first corner");
	if (board[1][1]==none) //try going at corner 1 first
	{
		return (1);
	}

	verbosePrint((char*)"trying middle");
	if ((board[1][1]==whoToMove||board[1][BOARD_SIZE]==whoToMove||board[BOARD_SIZE][1]==whoToMove||board[BOARD_SIZE][BOARD_SIZE]==whoToMove)&&isEmpty(5)) //if any corners are filled go to middle
	{
		return (5);
	}

	verbosePrint((char*)"trying other corners");
	//try the corners
	if (board[1][BOARD_SIZE]==none)
	{
		return (3);
	}
	if (board[BOARD_SIZE][1]==none)
	{
		return (7);
	}
	if (board[BOARD_SIZE][BOARD_SIZE]==none)
	{
		return (9);
	}
	if (board[1][1]==none)
	{
		return (1);
	}

	verbosePrint((char*)"trying left overs");
	/* (BOARD_SIZE * BOARD_SIZE) is needed to test all the available spots*/
	for (int tmp=1;tmp<=(BOARD_SIZE * BOARD_SIZE);tmp++)
	{
		if (isEmpty(tmp))
		{
			return (tmp);
		}
	}
	/* I don't this should ever be reached */
	cerr << "reaching end of turn function" << endl;
	return 0;
}

/* return true or false, based on weathr spot is empty */
inline bool isEmpty(int space)
{
	int row, col;
	row = getRowFromID(space);
	col = getColFromID(space);
	return (board[row][col]==none);
}
/* Retrieves a integer from the user. */
long int GetInteger(int base)
{
	/* allow 0 for computer move */ 
	/*TODO this really should be checked somewhere else*/
      int n = 0;

      n = strtol(getcharcters(10),NULL,10);

      if ( n <= 0 )
      {
            n = GetInteger(base);
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

inline void verbosePrint(char* str, bool isError) /*TODO: should change this to some method of passing stdin/stderr/...*/
{
	if (flag_verbose == TRUE)
	{
		if (isError == TRUE)
			cerr << str << endl;
		else
			cout << str << endl;
	}
}
