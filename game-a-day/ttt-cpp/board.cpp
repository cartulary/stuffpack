#include "board.h"
#include "piece.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.h>
#include <iostream>

using namespace ttt;


extern Board foo;
void button_cb(Fl_Widget* w, void* d)
{
	w->label(PieceToString(X));
	foo.setSpot(3,X);
}

Board::Board()
{
	char * x[] = {""};
	Fl_Window *window = new Fl_Window(WINDOW_SIZE,WINDOW_SIZE);
		int count = 0;
		buttons[count++] = new Fl_Button(1, 1, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));
		buttons[count++] = new Fl_Button(100, 1, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));
		buttons[count++] = new Fl_Button(200, 1, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));

		buttons[count++] = new Fl_Button(1, 100, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));
		buttons[count++] = new Fl_Button(100, 100, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));
		buttons[count++] = new Fl_Button(200, 100, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));

		buttons[count++] = new Fl_Button(1, 200, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));
		buttons[count++] = new Fl_Button(100, 200, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));
		buttons[count++] = new Fl_Button(200, 200, BUTTON_SIZE, BUTTON_SIZE, PieceToString(NONE));

		int i;
		for (i=0; i<count; ++i)
		{
			buttons[i]->callback(button_cb, NULL);
		}

 	window->end();
	window->show(1,x);
	Fl::run();
}

void Board::setSpot(const int id, const Piece p)
{
	buttons[id]->label(PieceToString(p));
}
