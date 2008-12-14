#include "functions.h"
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;
int cGetinteger(int base)
{
 	char mesg[]="How many blocks do you have: ";
	char str[80];
	int row,col;
	long finalVal=0;
	while (finalVal<=0)
	{
		clear();				/* clear the screen; use erase() instead? */
	 	initscr();				/* start the curses mode */
 		getmaxyx(stdscr,row,col);		/* get the number of rows and columns */
	 	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);     /* print the message at the center of the screen */
		getstr(str);
		endwin();
		finalVal = strtol(str,NULL,base);
	}
	if (finalVal <=0)
	{
		cerr << "Please enter a valid integer" << endl;
		exit(1);
	}
	return finalVal;
}
