/*
Tik-Tak-Toe CTY Final Project
Version 0.02
*/

//Includes
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "math.h"
#include "string.h"

//typedefs
typedef enum
{
	none, X, O
} player;

//prototypes of functions
int getMove(void); //gets a number for the move the player wants to make and ensures accuracy with the current board
void displayBoard(void); //shows the current board
bool checkWin(void); //if someone won then returns true
void initBoard(void); //starts board as all 'none's
player switchTurn(player toSwitch); //changes from X to O or vice-versa
char playerToString(player toConvert);  //changes a player type to a string type
int getRowFromID(int id); //returns the row from a num btwn 1 and 9
int getColFromID(int id); //returns the col from a num btwn 1 and 9
bool openSpace(void); //return true if there is an open space
int getComputerMove(player compPlayer); //get's the computer's move
int nextMoveWin(int lastMove); //tell the computer what to do if there is one open space for a win
int getID(int row, int col); //return a single digit number from a row and a col
bool isEmpty(int space); //returns true if space passed to it is true
int compMoveMain(int lastMove); //this is the comp move, it is there to correct some bugs
int compMove();  //called by compMoveMain due to slight bug.
long int GetInteger(int base);
char* getcharcters(int max);


//Create global vars
#define boardSize 3

player board[boardSize+1][boardSize+1]; //a 3x3 board except that the array starts at 0 so it is size+1
player turn; //current turn
using namespace std;

int main (void)
{
	turn = X; 
	bool cont=true;
	printf("Welcome to tik-tak-toe with a 'k'\n\n");
	printf("X (the computer) moves first\n");
	int lastMoveX=1,lastMoveO;
	do
	{
		cont=(openSpace()); //if there is no open space stop
		if (cont)
		{
			if (turn==X) {lastMoveX = compMoveMain(lastMoveX);} //get the move that the player wants to do
			if (turn==O) {lastMoveO = getMove();} //get the move that the player wants to do
			displayBoard(); //show the board AFTER the move is made
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
		printf("\n So you tied... :-(");
	}
}


inline void displayBoard(void)
{
	player current;
	int count=0;
	printf("\n");
	for (int row=1;row<=3;row++)
	{
		for (int col=1;col<=3;col++)
		{
			count++;
			current = board[row][col];
			printf("   ");
			if (current==none){printf("%d",count);}
			if (current==X){printf("X");}
			if (current==O){printf("O");}
			printf("\t|\t");
		}
		printf("\n--------|---------------|---------------|\n");
	}
	printf("\n");
}
inline void initBoard(void)
{
	for (int row=0;row<=boardSize;row++)
	{
		for (int col=0;col<=boardSize;col++)
		{
			board[row][col]=none;
		}
	}
}

inline int getMove(void)
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
			cerr << "programming error invalid player" <<endl;
			exit(1);
	}
}

inline player switchTurn(player toSwitch)
{
	switch (toSwitch)
	{
		case O:
			return O;
		case X:
			return X;
            default:
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
	if (tmp==0){tmp=3;}
	return (tmp); 
}

inline bool checkWin(void)
{
	/*
	I would check f	or neignbors, but it onvolves the smame amount of time due to checking to see what row.col it is
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
	for (int row=1;row<=boardSize;row++)
	{
		for (int col=1;col<=boardSize;col++)
		{
			if (board[row][col]==none){return (true);} //if there is an open space say so
		}
	}
	return (false); //if it completes the loop there is no open space
}

int nextMoveWin(int lastMove)
{
	int row, col;
	row = getRowFromID(lastMove);
	col = getColFromID(lastMove);
	int emptySpace;
	
	for (int rowCounter=1;rowCounter<=boardSize;rowCounter++)
	{
		if (row!=rowCounter)
		{
			emptySpace = 6-row-rowCounter;
			if (board[row][col]==board[rowCounter][col]&&board[rowCounter][col]!=none) //keep col same.
			{
				if (board[emptySpace][col]==none)
				{
					if (board[row][col]==X) {return (getID(emptySpace, col));}
				}

			}
		}
	}
	for (int colCounter=1;colCounter<=boardSize;colCounter++)
	{
		if (col!=colCounter)
		{
			emptySpace = 6-col-colCounter;
			if (board[row][colCounter]==board[row][col]&&board[row][colCounter]!=none)  //keep row same.
			{
				if (board[row][emptySpace]==none)
				{
					if (board[row][col]==X) {return (getID(row, emptySpace));}
				}
			}
		}
	}	

	//by now you either won't winr you will win by diag
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

inline int getID(int row, int col) //returns a number 1 through 9 from a row and col
{
	return ((3 * row) + col -3);
}

inline int compMoveMain(int lastMove)
{
	int nextMove;
	int row, col;
	nextMove = nextMoveWin(lastMove); //nextMove becomes the number of the next wining spot, 0 if no next move win
	if (nextMove==0) //if not next move win, try different set of moves
	{
		nextMove = compMove();
	}
	row = getRowFromID(nextMove);
	col = getColFromID(nextMove);
	board[row][col]=X; //set computers move
	return (nextMove);

}
inline int compMove()
{
	if (board[1][1]==none) //try going at corner 1 first
	{
		return (1);
	}

	if ((board[1][1]==X||board[1][3]==X||board[3][1]==X||board[3][3]==X)&&isEmpty(5)) //if any corners are filled go to middle
	{
		return (5);
	}

	//try the corners
	if (board[1][3]==none)
	{
		return (3);
	}
	if (board[3][1]==none)
	{
		return (7);
	}
	if (board[3][3]==none)
	{
		return (3);
	}
	if (board[1][1]==none)
	{
		return (1);
	}

	for (int tmp=1;tmp<=9;tmp++)
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

inline bool isEmpty(int space)
{
	int row, col;
	row = getRowFromID(space);
	col = getColFromID(space);
	return (board[row][col]==none); //return true or false, based on weathr spot is empty
}
/* Retrieves a positive integer from the user. */
long int GetInteger(int base)
{
      int n = 0;

      cout << "Please enter a positive integer:" << endl;
      n = strtol(getcharcters(10),NULL,10);

      if (n <= 0)
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
      
      str[max] = NULL; //I hope this is the right way to terminate a char array.
      return str;
}
