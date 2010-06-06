package ttt;
import static java.lang.System.out;
import java.io.IOException;
import java.util.*;

public class Game implements ButtonPressed {

	public TttBoard myboard;
  public Game() {
		myboard = new TttBoard(this);
		myboard.bpx = this;
		myboard.start();
		AskAgain asker = new AskAgain();
//		myboard.disableButton(1);
		while (asker.ask())
		{}
	}

	public void didPress(int id)
	{
		System.out.println(id);
		myboard.setButton(id, Piece.X);
	}
}
