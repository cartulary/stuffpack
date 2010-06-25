#ifndef PIECE_H
#define PIECE_H
#include <string>
namespace ttt
{
	enum Piece {
		X,
		O,
		NONE
	};
	char const* PieceToString(const Piece p);
}
#endif
