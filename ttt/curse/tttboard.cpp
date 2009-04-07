/*
	maintains a board and returns win/loss and next-move data
*/
class tttBoard
{
	enum player { X, O, none };
	private:
		bool setPosition(player piece, int row, int col, bool force = false)
		{
			if (board[row][col] != none || force)
			{
				board[row][col] = piece;
				return true;
			}
			return false;
		}
	public:
		player board[3][3];
		const char *strPlayers[3];
		tttBoard()
		{
			this->strPlayers[0] = "X";
			this->strPlayers[1] = "O";
			this->strPlayers[2] = "";
			int i,j;
			for (i = 0; i<=2; ++i)
			{
				for (j= 0; j<=2; ++j)
				{
					board[i][j] = none;
				}
			}
		}
		bool requestPosition(player piece, int row, int col)
		{
			return setPosition(piece, row, col);
		}
};

