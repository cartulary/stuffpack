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
		
		display.setMaximumSize(new Dimension(500, 20));
		display.setEditable(false);
		
		
//		Initialize the keyboard buttons:
		
		JButton button0 = new JButton("0");
		JButton button1 = new JButton("1");
		JButton button2 = new JButton("2");
		JButton button3 = new JButton("3");
		JButton button4 = new JButton("4");
		JButton button5 = new JButton("5");
		JButton button6 = new JButton("6");
		JButton button7 = new JButton("7");
		JButton button8 = new JButton("8");
		JButton button9 = new JButton("9");
		JButton buttonEquals = new JButton("=");
		JButton buttonAdd = new JButton("+");
		JButton buttonSubtract = new JButton("-");
		JButton buttonMultiply = new JButton("*");
		JButton buttonDivide = new JButton("/");
		JButton buttonPoint = new JButton(".");
		JButton buttonBackspace = new JButton("<--");
		JButton buttonClear = new JButton("C");
		JButton buttonModulus = new JButton("%");
		
//		This button doesn't do enything. It's just there to keep the layout clean:
		
		JButton dfs = new JButton("dfs");
		
//		Register the keyboard button's event listeners:
		
		button0.addActionListener(addChar);
		button1.addActionListener(addChar);
		button2.addActionListener(addChar);
		button3.addActionListener(addChar);
		button4.addActionListener(addChar);
		button5.addActionListener(addChar);
		button6.addActionListener(addChar);
		button7.addActionListener(addChar);
		button8.addActionListener(addChar);
		button9.addActionListener(addChar);
		buttonAdd.addActionListener(addChar);
		buttonSubtract.addActionListener(addChar);
		buttonMultiply.addActionListener(addChar);
		buttonDivide.addActionListener(addChar);
		buttonModulus.addActionListener(addChar);
		buttonPoint.addActionListener(addChar);
		buttonEquals.addActionListener(performCalculation);
		buttonBackspace.addActionListener(removeLast);
		buttonClear.addActionListener(removeAll);
		
//		Content pane setup:
		
		contentPane.setLayout(new BoxLayout(contentPane, BoxLayout.PAGE_AXIS));
		contentPane.add(display);
		contentPane.add(keyboard);
		
//		Keyboard setup:
		
		keyboard.setLayout(new GridLayout(5, 4));
		
		keyboard.add(buttonBackspace);
		keyboard.add(buttonClear);
		keyboard.add(dfs);
		keyboard.add(buttonAdd);
		
		keyboard.add(button7);
		keyboard.add(button8);
		keyboard.add(button9);
		keyboard.add(buttonSubtract);
		
		keyboard.add(button4);
		keyboard.add(button5);
		keyboard.add(button6);
		keyboard.add(buttonMultiply);
		
		keyboard.add(button1);
		keyboard.add(button2);
		keyboard.add(button3);
		keyboard.add(buttonDivide);
		
		keyboard.add(button0);
		keyboard.add(buttonPoint);
		keyboard.add(buttonEquals);
		keyboard.add(buttonModulus);
		
//		Window setup:
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setTitle("SysCalculator");
		this.setSize(new Dimension(200, 220));
		
		ArrayList<Image> gnomeIcon = new ArrayList<Image>();
		gnomeIcon.add(this.getImage("icons/gnome_16x16.png"));
		gnomeIcon.add(this.getImage("icons/gnome_22x22.png"));
		gnomeIcon.add(this.getImage("icons/gnome_24x24.png"));
		gnomeIcon.add(this.getImage("icons/gnome_32x32.png"));
		
		this.setIconImages(gnomeIcon);
		this.setResizable(false);
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
		catch (UnsupportedLookAndFeelException e) {
//			handle exception
		}
		catch (ClassNotFoundException e) {
//			handle exception
		}
		catch (InstantiationException e) {
//			handle exception
	    }
		catch (IllegalAccessException e) {
//			handle exception
		}
		
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
