#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.h>
#include <iostream>
#include "board.h"
#include "piece.h"
using namespace ttt;

extern Board foo;
#include "callback.cpp"

Board::Board()
{
	char * x[] = {""};
	int const nums[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
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
			buttons[i]->callback(button_cb, (void*)(&nums[i]));
			//for the users start at 1 ;)
			buttons[i]->shortcut('1'+i);
		}

 	window->end();
	window->show(1,x);
	Fl::run();
}

void Board::setSpot(const int id, const Piece p)
{
	buttons[id]->label(PieceToString(p));
}

void Board::disableSpot(const int id)
{
	buttons[id]->deactivate();
}

void Board::enableSpot(const int id)
{
	buttons[id]->activate();
}

Piece Board::getSpot(const int id) const
{
	return StringToPiece(buttons[id]->label());
}

