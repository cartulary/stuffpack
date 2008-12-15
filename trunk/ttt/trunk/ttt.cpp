#include <stdio.h>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>


#define PLAYER_X 1
#define PLAYER_O 2
#define PLAYER_NO 0 /* no player */

#define TEXT_X 'X'
#define TEXT_O 'O'

#define BOARD_SIZE 3

void showBoard(int board[BOARD_SIZE][BOARD_SIZE]);
char playerToText(int player, char ifNot);
int spotToNum(int x,int y);

using namespace std;

int main(void)
{
	int board[BOARD_SIZE][BOARD_SIZE] =
		{
 			{ PLAYER_NO, PLAYER_NO, PLAYER_NO},
 			{ PLAYER_NO, PLAYER_NO, PLAYER_NO},
 			{ PLAYER_NO, PLAYER_NO, PLAYER_NO}
		};
	showBoard(board);
	return 0;
}

bool checkWin(int board[BOARD_SIZE][BOARD_SIZE])
{
	return false;
}

void showBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
	int i,j;
	char showText;
	/* i is row; j is col */
	for (i=0; i<=BOARD_SIZE - 1; i++)
	{
		for (j=0; j<=BOARD_SIZE - 1; j++)
		{
			showText = (char)(spotToNum(i,j));
			printf("%c ",playerToText(board[i][j],showText));
		}
		cout << endl;
	}
}

int spotToNum(int x,int y)
{
	return ((BOARD_SIZE * (y + 1) ) - (BOARD_SIZE - x - 1));
}

char playerToText(int player,char ifNot)
{
	if (player==PLAYER_X)
	{
		return TEXT_X;
	}
	if (player==PLAYER_O)
	{
		return TEXT_O;
	}
	return ifNot+48;
}
