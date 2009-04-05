#include "ttt.h"

#include <iostream>
#include <ncurses.h>
#include <signal.h>

static void finish(int sig);
static void initCurses();

int main(int argc, char *argv[])
{
	(void) signal(SIGINT, finish);
	initCurses();

	mvprintw(0,0,"Welcome to tik tak toes!");
	while (true)
	{
	   	int c = getch();/* refresh, accept single keystroke of input */
		switch (c)
		{
			case 'q':
				finish(SIGINT);
				break;
			
		}
	}

	finish(0);/* we're done */
}

static void finish(int sig)
{
	if (sig == SIGINT)
	{
		endwin();
		exit(0);
	}
}

static void initCurses()
{

	(void) initscr(); /* initialize the curses library */
	keypad(stdscr, TRUE);  /* enables the reading of function keys  */
	(void) nonl();	/* tell curses not to do NL->CR/NL on output */
	(void) cbreak();	/* take input chars one at a time, no wait for \n */
	(void) noecho();	/* don't echo input */
	if (has_colors())
	{
		start_color();

		/*
	 	* Simple color assignment, often all we need.
 		*/
		init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
		init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
		init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
		init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
		init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
		init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	}
}
