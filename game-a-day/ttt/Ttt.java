import static java.lang.System.out;
import java.io.IOException;
import java.util.*;

class Ttt {
  public static void main(String[] args) {
		TttBoard myboard = new TttBoard();
		myboard.setSpot(1,1,Piece.X);
		myboard.printBoard();
	}
}
