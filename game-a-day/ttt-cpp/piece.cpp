#include "piece.h"
namespace ttt {

char const * PieceToString(const Piece p)
{
        switch(p)
        {
            case X:
                return "X";
            case O:
                return "O";
            case NONE:
                return "NONE";
        }
}

Piece StringToPiece(char const* const s)
{
	if (s == "X")
	{
		return X;
	}

	if (s == "O")
	{
		return O;
	}

	return NONE;
}

}
