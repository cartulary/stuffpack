	/*
	There is almost no error handling here in order that the users of the class learn
	how do deal with this themselves
*/
package ttt;
//import java.awt.*;
import java.awt.GridLayout;
import java.awt.Font;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

/**
	This class implements the graphical part of a Tic Tac Toe board.
	@author Eitan Adler
	@version 1
*/

public class TttBoard implements ActionListener {

	/* The stuff for the window */
	private final int BUTTON_COUNT=9;
	private JFrame window = new JFrame("Tic Tac Toe");
	private List<JButton> buttons = new ArrayList<JButton>(BUTTON_COUNT);
	private Piece turn = Piece.NONE;
	private ButtonPressed bpx;

	// ROWS FIRST /COLUMNS SECOND
	/**
		The ctor creates the buttons and windows and associates relevent styles.
		@param bp the ButtonPressed interface that the board called when it gets clicked
	*/
	public TttBoard(ButtonPressed bp)
	{
		bpx = bp;
		Font buttonFont = new Font("Verdana", Font.BOLD, 48);

		window.setSize(300,300);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setLayout(new GridLayout(3,3));

		for (int i=0; i < BUTTON_COUNT; ++i)
		{
			JButton tmpButton = new JButton();
			tmpButton.addActionListener(this);
			tmpButton.setFont(buttonFont);
			tmpButton.setSize(100,100);
			tmpButton.setText(Piece.NONE.toString());
			window.add(tmpButton);
			buttons.add(tmpButton);
		}
		window.setVisible(true);
	}

	/**
		@return returns the piece that a particular button is currently displaying
	*/
	public Piece getSpot(int id)
	{
		return Piece.valueOf(buttons.get(id).getText());
	}

	/**
		This function gets called whenever a button is pressed
		@param e the source of the event
	*/
	public void actionPerformed(ActionEvent e)
	{
		JButton whichButton = (JButton)e.getSource();
		for (int i=0; i < BUTTON_COUNT; ++i)
		{
			if (buttons.get(i) == whichButton)
			{
				bpx.didPress(i);
			}
		}
		//ERROR!!!
	}

	/**
		Disable a particular button
		@param id which button to disable
	*/

	public void disableButton(int id)
	{
		buttons.get(id).setEnabled(false);
	}

	/**
		set a button to a particular piece
		@param id which button to set
		@param p what to set it to
	*/
	public void setButton(int id, Piece p)
	{
		buttons.get(id).setText(p.toString());
	}
}
