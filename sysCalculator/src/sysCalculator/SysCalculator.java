package sysCalculator;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.net.URL;

/**
 * @author yitz
 * @version 1.2
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
	 * @author yitz
	 * @since 1.1
	 */
	private ActionListener removeLast= new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			String displayText = display.getText();
			if (!displayText.isEmpty()) {
				display.setText(displayText.substring(0, displayText.length() - 1));
			}
		}
	};

	/**
	 * @author yitz
	 * @since 1.1
	 */
	private ActionListener removeAll = new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			display.setText("");
		}
	};

	/**
	 * @author yitz
	 * @since 1.0
	 */
	private ActionListener addChar = new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			
//			Cache the display text and action command:
			
			String displayText = display.getText();
			String actionCommand = e.getActionCommand(); 
			
//			Check to make sure that you don't get a problem that starts with a symbol or ends with 2 symbols in a row: 
			
			if ((!displayText.isEmpty() && !SysCalculator.isOperator(displayText.charAt(displayText.length() - 1)) &&
					!displayText.endsWith(".")) || !SysCalculator.isOperator(actionCommand.charAt(0))) {
				
//				If the conditions are satisfied, append the character that is printed on the label to the display:
				
				display.setText(displayText + actionCommand);
			}
		}
	};

	/**
	 * @author yitz
	 * @since 1.0
	 */
	private ActionListener performCalculation = new ActionListener() {
		public void actionPerformed(ActionEvent e) {
			
//			Cache the display text:
			
			String displayText = display.getText();
			
//			Make sure that the problem doesn't end with an operator befor performing the operation:
			
			if (!SysCalculator.isOperator(displayText.charAt(displayText.length() - 1))) {
				
//				Get an array of all the operands:
				
				String[] numbers = displayText.split("[\\+\\-\\*\\/\\%]");
				
//				Convert the array to an ArrayList, so that the remove() function can be used:
				
				ArrayList<String> operands = new ArrayList<String>();
				
				for (String s : numbers) {
					operands.add(s);
				}
				
//				Go over each character in the display, and if it's an operator then add to an ArrayList:
				
				ArrayList<String> operators = new ArrayList<String>();
				
				for (int i = 0; i < displayText.length(); i++) {
					if (SysCalculator.isOperator(displayText.charAt(i))) {
						operators.add(displayText.charAt(i) + "");
					}
				}
				
//				Solve from left to right, in complete disregard of correct algebraic order:
				
				double currentResult = Double.parseDouble(operands.get(0));
				operands.remove(0);
				for (int i = 0; i < operands.size(); i++) {
					currentResult = SysCalculator.calculate(currentResult, Double.parseDouble(operands.get(i)), operators.get(i).charAt(0));
				}
				
//				Display the solution of the problem:
				
				display.setText(currentResult + "");
			}
		}
	};

	
	/**
	 * Sets up the GUI.
	 * @author yitz
	 * @since 1.0
	 */
	public SysCalculator() {
		Container contentPane = this.getContentPane();
		JPanel keyboard = new JPanel();
		
//		Display setup:
		
		display.setEditable(false);
		
//		Content pane setup:
		
		contentPane.add(keyboard, BorderLayout.CENTER);
		
//		Keyboard setup:
		
		ArrayList<JButton> buttons = new ArrayList<JButton>();
		ArrayList<String> labels = new ArrayList<String>();
		labels.add("<--");
		labels.add("C");
		labels.add("+");
		
		labels.add("7");
		labels.add("8");
		labels.add("9");
		labels.add("-");
		
		labels.add("4");
		labels.add("5");
		labels.add("6");
		labels.add("*");
		
		labels.add("1");
		labels.add("2");
		labels.add("3");
		labels.add("/");
		
		labels.add("0");
		labels.add(".");
		labels.add("=");
		labels.add("%");
		
		for (String label : labels) {
			JButton button = new JButton(label);
			buttons.add(button);
			
			if (label == "<--") {
				button.addActionListener(removeLast);
			}
			else if (label == "C") {
				button.addActionListener(removeAll);
			}
			else if (label == "=") {
				button.addActionListener(performCalculation);
			}
			else {
				button.addActionListener(addChar);
			}
		}
		
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
	 * @since 1.2
	 * @param operator
	 * @return
	 */
	public static boolean isOperator(char operator) {
		String operators = "+-*/%";
		if (operators.indexOf(operator) > -1) {
			return true;
		}
		else {
			return false;
		}
	}
	
	/**
	 * Perform binary mathematical operations. Currently only addition, subtraction, multiplication, division, and modulus are supported.
	 * @author yitz
	 * @since 1.0
	 * @param operandA One of the two operands of the binary operation. 
	 * @param operandB One of the two operands of the binary operation.
	 * @param operator The character that sybolizes the binary operation that will be performed.
	 * @return The result of the calculation.
	 */
	public static double calculate(double operandA, double operandB, char operator) {
		switch (operator) {
			case '+':
				return operandA + operandB;
			case '-':
				return operandA - operandB;
			case '*':
				return operandA * operandB;
			case '%':
				return operandA % operandB;
			default:
				return operandA / operandB;
		}
			
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