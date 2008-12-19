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
player stringToPlayer(char toConvert);  // changes a string to a player
int getRowFromID(int id); //returns the row from a num btwn 1 and 9
int getColFromID(int id); //returns the col from a num btwn 1 and 9
bool openSpace(void); //return true if there is an open space
int getComputerMove(player compPlayer); //get's the computer's move
int nextMoveWin(int lastMove,player whoToWin); //tell the computer what to do if there is one open space for a win
int getID(int row, int col); //return a single digit number from a row and a col
bool isEmpty(int space); //returns true if space passed to it is true
int compMoveMain(int lastMove, player whoToMove); //this is the comp move, it is there to correct some bugs
int compMove(player whoToMove);  //called by compMoveMain due to slight bug.
long int GetInteger(int base);
char* getcharcters(int max);
void verbosePrint(char* str, bool isError = 0 );

//Create global vars
#define TRUE 1
#define FALSE 0

#define BOARD_SIZE 3

#define TURN_PLAYER O
#define TURN_COMP X

#define MODE_EASY 1
#define MODE_HARD 2


#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <sysexits.h>

#include <stdio.h>
#include <ctype.h>
#include "math.h"
#include <getopt.h>
