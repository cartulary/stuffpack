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
	Piece StringToPiece(char const* const s);
}
#endif
