package sysCalculator;

import java.util.ArrayList;

public class Calculator {

	/**
	 * Check whether or not the given character is a supported operator.
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
	 * 
	 * @author yitz
	 * @since 1.3
	 * @param problemString A regular string that represents a mathematical problem.
	 * @return An array that's ready to be processed by Calculator.solve(String[]).
	 */
	public static String[] compile(String problemString) {
		
//		Get an array of all the operands:
		
		String[] numbers = problemString.split("[\\+\\-\\*\\/\\%]");
		
//		Go over each character in the display, and if it's an operator then add to an ArrayList:
		
		ArrayList<String> operators = new ArrayList<String>();
		
		for (int i = 0; i < problemString.length(); i++) {
			if (Calculator.isOperator(problemString.charAt(i))) {
				operators.add(problemString.charAt(i) + "");
			}
		}
		
//		Compile the problem into an ArrayList:
		
		ArrayList<String> problem = new ArrayList<String>();
		
		for (int i = 0; i < operators.size(); i++) {
			problem.add(numbers[i]);
			problem.add(operators.get(i));
		}
		
		problem.add(numbers[numbers.length - 1]);
		
//		Convert the problem ArrayList into a primitive array:
		
		String[] problemArray = new String[problem.size()];
		
		for (int i = 0; i < problem.size(); i++) {
			problemArray[i] = problem.get(i);
		}
		return problemArray;
	}
	
	/**
	 * Solves the given mathematical problem.
	 * @author yitz
	 * @since 1.3
	 * @param problem The problem to be solved.
	 * @return The solution to the problem.
	 */
	public static double solve(String[] problem) {
		
//		Solve from left to right, in complete disregard of correct algebraic order:
//		TODO: Make it solve the problem in correct algebraic order.
		double currentResult = Double.parseDouble(problem[0]);
		
		for (int i = 1; i < problem.length; i++) {
			if (i % 2 != 0) {
				currentResult = Calculator.calculate(currentResult, Double.parseDouble(problem[i + 1]), problem[i].charAt(0));
			}
		}
		return currentResult;
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

}
