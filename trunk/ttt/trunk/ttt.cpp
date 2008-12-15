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
using namespace std;

int main(void)
{
	int player = PLAYER_NO;
	int wantSquare;
	int row,col;
	int board[BOARD_SIZE][BOARD_SIZE] =
		{
 			{ PLAYER_NO, PLAYER_NO, PLAYER_NO},
 			{ PLAYER_NO, PLAYER_NO, PLAYER_NO},
 			{ PLAYER_NO, PLAYER_NO, PLAYER_NO}
		};
	int i,j,k;

	showBoard(board);

	printf("\n\n");
      printf(" %d | %d | %d\n", board[0][0], board[0][1], board[0][2]);
      printf("---+---+---\n");
      printf(" %d | %d | %d\n", board[1][0], board[1][1], board[1][2]);
      printf("---+---+---\n");
      printf(" %d | %d | %d\n", board[2][0], board[2][1], board[2][2]);

	return 0;
}

bool checkWin(int board[BOARD_SIZE][BOARD_SIZE])
{
	return false;
}

void showBoard(int board[BOARD_SIZE][BOARD_SIZE])
{
	int i,j;
	char charToShow;
	/* i is row; j is col */
	for (i=0; i<=BOARD_SIZE-1; i++)
	{
		for (j=0; j<=BOARD_SIZE-1; j++)
		{
			charToShow = (char)((BOARD_SIZE * i) - (BOARD_SIZE - j)); //get the "number"
			if (board[i][j]==PLAYER_X)
			{
				charToShow = TEXT_X;
			}
			if (board[i][j]==PLAYER_O)
			{
				charToShow = TEXT_X;
			}

			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
