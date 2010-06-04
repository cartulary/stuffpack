/*
	There is almost no error handling here in order that the users of the class learn
	how do deal with this themselves
*/
package ttt;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TttBoard implements ActionListener {

	/* The stuff for the window */
	private JFrame window = new JFrame("Tic Tac Toe");
	private JButton buttons[] = new JButton[9];
	private Piece turn = Piece.NONE;
	private ButtonPressed bpx;

	// ROWS FIRST /COLUMNS SECOND
	public TttBoard(ButtonPressed bp)
	{
		bpx = bp;
		Font buttonFont = new Font("Verdana", Font.BOLD, 48);

		window.setSize(300,300);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setLayout(new GridLayout(3,3));

		for (JButton button: buttons)
		{
			button = new JButton();
			window.add(button);
			button.addActionListener(this);
			button.setFont(buttonFont);
			button.setSize(100,100);
			button.setText(Piece.NONE.toString());
		}
		window.setVisible(true);
	}

	public Piece getSpot(int id)
	{
		return Piece.valueOf(buttons[id].getText());
	}

	public void actionPerformed(ActionEvent e)
	{
		JButton whichButton = (JButton)e.getSource();
	}

	public void disableButton(int i)
	{
		buttons[i].setEnabled(false);
	}

	public void setButton(int id, Piece p)
	{
		buttons[id].setText(p.toString());
	}
}
