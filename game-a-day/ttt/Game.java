package ttt;
import static java.lang.System.out;
import java.io.IOException;
import java.util.*;

public class Game implements ButtonPressed {

	public TttBoard myboard;
  public Game() {
		myboard = new TttBoard(this);
		AskAgain asker = new AskAgain();
//		myboard.disableButton(1);
//		while (asker.ask())
		{}
	}

	public void didPress(int id)
	{
		System.out.println(id);
		myboard.setButton(id, Piece.X);
		if (id==3)
		{
			myboard.setButton(id,Piece.O);
		}
		myboard.disableButton(id);
	}
}
