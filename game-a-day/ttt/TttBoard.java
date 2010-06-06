/*
	There is almost no error handling here in order that the users of the class learn
	how do deal with this themselves
*/
package ttt;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
	This class implements the graphical part of a Tic Tac Toe board.
	@author Eitan Adler
	@version 1
*/

public class TttBoard implements ActionListener {

	/* The stuff for the window */
	private JFrame window = new JFrame("Tic Tac Toe");
	private JButton buttons[] = new JButton[9];
	private Piece turn = Piece.NONE;
	public ButtonPressed bpx;

	// ROWS FIRST /COLUMNS SECOND
	/**
		The ctor creates the buttons and windows and associates relevent styles.
		@param bp the ButtonPressed interface that the board called when it gets clicked
	*/
	public TttBoard(ButtonPressed bp)
	{
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

	/**
		@return returns the piece that a particular button is currently displaying
	*/
	public Piece getSpot(int id)
	{
		return Piece.valueOf(buttons[id].getText());
	}

	/**
		This function gets called whenever a button is pressed
		@param e the source of the event
	*/
	public void actionPerformed(ActionEvent e)
	{
		JButton whichButton = (JButton)e.getSource();
//		bpx.didPress(1);
	}

	/**
		Disable a particular button
		@param i which button to disable
	*/

	public void disableButton(int i)
	{
		buttons[i].setEnabled(false);
	}

	/**
		set a button to a particular piece
		@param id which button to set
		@param p what to set it to 
	*/
	public void setButton(int id, Piece p)
	{
		buttons[id].setText(p.toString());
	}

	public void start()
	{
		window.setVisible(true);
	}
}
