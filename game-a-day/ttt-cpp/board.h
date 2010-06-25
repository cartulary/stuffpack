#ifndef BOARD_H
#define BOARD_H
#include <FL/Fl_Button.H>
#include <vector>
#include "piece.h"

namespace ttt
{

class Board {
	Fl_Button* buttons[9];
	const static int WINDOW_SIZE = 300;
	const static int BUTTON_SIZE = WINDOW_SIZE / 3;
public:
	Board();
	void setSpot(const int id, const Piece p);
	Piece getSpot(const int id) const;
	void disableSpot(const int id);
	void enableSpot(const int id);
};

}
#endif
