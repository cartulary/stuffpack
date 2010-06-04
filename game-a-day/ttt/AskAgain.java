package ttt;
import javax.swing.JOptionPane;

class AskAgain {
  public static Boolean ask() {
		final int r = JOptionPane.showConfirmDialog(null,"Tic Tac Toe","Would you like to play again",JOptionPane.YES_NO_OPTION);
		if (r == JOptionPane.YES_OPTION)
		{
			return true;
		}
		return false;
	}
}
