package sysCalculator;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.net.URL;

/**
 * @author yitz
 * @version 1.3
 * @since 1.0
 */

public class SysCalculator extends JFrame {
	
	/**
	 * The widget that stores the problem and displays it and the results on screen.
	 * @author yitz
	 * @since 1.0
	 */
	private JTextField display = new JTextField();
	
	/**
	 * SysCalculator's content pane.
	 * @author yitz
	 * @since 1.0
	 */
	private Container contentPane = this.getContentPane();
	
	/**
	 * The panel that holds the basic calculator interface.
	 * @author yitz
	 * @since 1.0
	 */
	private JPanel keyboard = new JPanel();
	
	/**
	 * The buttons that are part of the basic calculator interface.
	 * @author yitz
	 * @since 1.0
	 */
	private ArrayList<JButton> buttons = new ArrayList<JButton>();
	
	/**
	 * The button's labels. These define the button's functionality, so be carefull when making changes!
	 * @author yitz
	 * @since 1.3
	 */
	public static final String[] LABELS = {
			"<--", "C", "+", 
			"7", "8", "9", "-",
			"4", "5", "6", "*",
			"1", "2", "3", "/",
			"0", ".", "=", "%"
	};
	
	
	/**
	 * The action listener for all the buttons.
	 * @author yitz
	 * @since 1.3
	 */
	private ActionListener buttonPressed = new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			String actionCommand = e.getActionCommand();
			
			if (isBackspace(actionCommand)) {
				removeLast();
			}
			else if (isClear(actionCommand)) {
				clear();
			}
			else if (isEquals(actionCommand)) {
				performCalculation();
			}
			else {
				addCharacter(actionCommand.charAt(0));
			}
			
		}
	};
	
	/**
	 * Checks whether or not the given string is used to represent the backspace command. 
	 * @author yitz
	 * @since 1.3
	 */
	public boolean isBackspace(String s) {
		return s == "<--" ? true : false;
	}
	
	/**
	 * Checks whether or not the given string is used to represent the clear command.
	 * @author yitz
	 * @since 1.3
	 */
	public boolean isClear(String s) {
		return s == "C" ? true : false;
	}
	
	/**
	 * Checks whether or not the given string is used to represent the equals sign.
	 * @author yitz
	 * @since 1.3
	 */
	public boolean isEquals(String s) {
		return s == "=" ? true : false;
	}

	/**
	 * Removes the last character from the display.
	 * @author yitz
	 * @since 1.1
	 */
	private void removeLast() {
		String displayText = display.getText();
		if (!displayText.isEmpty()) {
			display.setText(displayText.substring(0, displayText.length() - 1));
		}
	}

	/**
	 * Clears the contents of the display.
	 * @author yitz
	 * @since 1.1
	 */
	private void clear() {
			display.setText("");
	}

	/**
	 * Appends the given character to the display.
	 * @author yitz
	 * @since 1.0
	 */
	private void addCharacter(char c) {
		
//		Cache the display text and action command:
		
		String displayText = display.getText();
		
//		Check to make sure that you don't get a problem that starts with a symbol or ends with 2 symbols in a row: 
		
		if ((!displayText.isEmpty() && !Calculator.isOperator(displayText.charAt(displayText.length() - 1)) &&
				!displayText.endsWith(".")) || !Calculator.isOperator(c)) {
			
//			If the conditions are satisfied, append the character that is printed on the label to the display:
			
			display.setText(displayText + c);
		}
	}

	/**
	 * Solves the mathematical problem stored in the display and displays the result.
	 * @author yitz
	 * @since 1.0
	 */
	private void performCalculation() {
		
//		Cache the display text:
		
		String displayText = display.getText();
		
//		Make sure that the problem doesn't end with an operator befor performing the operation:
		
		if (!Calculator.isOperator(displayText.charAt(displayText.length() - 1))) {
			
//			Perform the calculation and display the solution:
			
			display.setText(Calculator.solve(Calculator.compile(displayText))+ "");
		}
	}
	
	/**
	 * Sets up the GUI.
	 * @author yitz
	 * @since 1.0
	 */
	public SysCalculator() {
		
//		Display setup:
		
		display.setEditable(false);
		
//		Content pane setup:
		
		contentPane.add(keyboard, BorderLayout.CENTER);
		
		
//		Creating the buttons and registering their action listeners:
		
		
		for (String label : SysCalculator.LABELS) {
			JButton button = new JButton(label);
			buttons.add(button);
			button.addActionListener(buttonPressed);
		}
		
//		Keyboard setup:
		
		keyboard.setLayout(new GridBagLayout());
		GridBagConstraints c = new GridBagConstraints();
		
		Insets insets = new Insets(2, 2, 2, 2);
		int y = 1, x = 0;
		
		c.gridx = 0;
		c.gridy = 0;
		c.fill = GridBagConstraints.BOTH;
		c.insets = insets;
		c.weightx = 0.1;
		c.weighty = 0.1;
		c.gridwidth = 4;
		
		keyboard.add(display, c);
		
		for (JButton button : buttons) {
			if (x == 1 && y == 1) {
				x = 2;
			}
			
			c.gridx = x;
			c.gridy = y;
			if (button.getText() == "<--") {
				c.gridwidth = 2;
			}
			else {
				c.gridwidth = 1;
			}
			
			keyboard.add(button, c);
			y = x == 3 ? y + 1 : y;
			x = x == 3 ? 0 : x + 1;
		}
		
//		Window setup:
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setTitle("SysCalculator");
		this.setSize(new Dimension(230, 250));
		
		ArrayList<Image> gnomeIcon = new ArrayList<Image>();
		gnomeIcon.add(this.getImage("icons/gnome_16x16.png"));
		gnomeIcon.add(this.getImage("icons/gnome_22x22.png"));
		gnomeIcon.add(this.getImage("icons/gnome_24x24.png"));
		gnomeIcon.add(this.getImage("icons/gnome_32x32.png"));
		
		this.setIconImages(gnomeIcon);
		this.setLocationRelativeTo(this);
		this.setVisible(true);
	}
	
	/**
	 * @author yitz
	 * @since 1.0
	 * @param args This parameter is unused.
	 */
	public static void main(String[] args) {
		try {
//			Set Java to use native Look & Feel:
			UIManager.setLookAndFeel(
			UIManager.getSystemLookAndFeelClassName());
		}
		catch (Exception e) {
//			Should I do somthing here? Somehow I think it unnecessary.
		}
		
//		Initialize the application:
		
		new SysCalculator();
	}
	
	/**
	 * Retrieve image files as Image objects.
	 * @author yitz
	 * @since 1.0
	 * @param path The path, relative or absolute, of the image to be loaded.
	 * @return The image stored in path.
	 */
	private Image getImage(String path) {
        URL imgURL = SysCalculator.class.getResource(path);
        if (imgURL != null) {
            return new ImageIcon(imgURL).getImage();
        } else {
            return null;
        }
    }
}