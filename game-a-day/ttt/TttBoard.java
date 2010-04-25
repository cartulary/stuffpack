public class TttBoard {
	// ROWS FIRST /COLUMNS SECOND
	private Piece[][] board;
	public TttBoard()
	{
		board = new Piece[3][3];
		for (Piece i[] : board)
		{
			for (Piece j : i)
			{
				j = Piece.NONE;
			}
		}
	}

	public Piece getSpot(int row, int column)
	{
		return board[row][column];
	}

	public void setSpot(int row, int column, Piece p)
	{
		board[row][column] = p;
	}

	public void printBoard()
	{
		for (Piece i[] : board)
		{
			for (Piece j : i)
			{
				java.lang.System.out.print(j + " ");
			}
			java.lang.System.out.print("\n");
		}
	}
}