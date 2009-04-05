#include <iostream>
#include <ncurses.h>
#include <signal.h>

enum player { X, O, none };
const char *strPlayers[] = {"X","O","-"};

static void finish(int sig);
static void initCurses();

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_window(WINDOW *local_window);

int main(int argc, char *argv[])
{
	const int title_window_height = 2;
	const int game_window_height = 10;
	const int help_window_height = 2;

	const int title_window_y_start = 0;
	const int game_window_y_start = title_window_y_start + title_window_height;
	const int help_window_y_start = game_window_y_start + game_window_height;

	player turn = X;

	(void) signal(SIGINT, finish);
	initCurses();
	WINDOW *game_window;
	WINDOW *title_window;
	WINDOW *help_window;
	WINDOW *turn_window;

	MEVENT mouse_event;
	mousemask(ALL_MOUSE_EVENTS, NULL);

	/* 4 arguments - height, width, starty, startx */
	title_window = create_newwin(title_window_height, COLS - 2, title_window_y_start, 0);
	game_window = create_newwin(game_window_height, COLS, game_window_y_start, 0);
	help_window = create_newwin(help_window_height, COLS, help_window_y_start, 0);
	turn_window = create_newwin(title_window_height, 2, title_window_y_start, COLS - 2);

	while (true)
	{
	   	int c = getch();/* refresh, accept single keystroke of input */
		switch (c)
		{
			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
				// do something with the selection here.
				break;
			case 't':
				turn = (turn == 0) ? O : X;
				break;
			case 'q':
				finish(0);
				break;
			case KEY_F(1):
				waddstr(help_window, "Add some help information");
				break;
			case '#':
				waddch(game_window, ACS_PLMINUS);
				break;
			case KEY_MOUSE:
				if(getmouse(&mouse_event) == OK)
				{
					if(mouse_event.bstate & BUTTON1_PRESSED)
					{
						waddstr(game_window,"please wait!");
					}
				}
				break;
			default:
				break;
		}
		if (c != NULL)
		{
			mvwaddstr(title_window, 0,0, "Welcome to tik tak toes!");
			wrefresh(title_window);
			wrefresh(game_window);
			wrefresh(help_window);
			mvwaddstr(turn_window,0,1,strPlayers[turn]);
			wrefresh(turn_window);
		}
	}

	finish(0);/* we're done */
}

static void finish(int sig)
{
	if (sig == SIGINT || sig == 0)
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


WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_window;
	local_window = newwin(height, width, starty, startx);
	wrefresh(local_window);
	return local_window;
}

void destroy_window(WINDOW *local_window)
{
	delwin(local_window);
}
