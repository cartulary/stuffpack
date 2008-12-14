#include "functions.h"

long getinteger(int base)
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
	return finalVal;
}
