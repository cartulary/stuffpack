package sysCalculator;

import java.util.ArrayList;

/**
 * The calculator's backend.
 * @author yitz
 * @version 1.3
 * @since 1.3
 */

public class Calculator {

	/**
	 * Check whether or not the given character is a supported operator.
	 * @since 1.2
	 * @param operator The character that is to be evaluated.
	 * @return Whether or not the given character represents a supported character.
	 */
	public static boolean isOperator(char operator) {
		if (isAdder(operator) || isMultiplier(operator)) {
			return true;
		}
		else {
			return false;
		}
	}
	
	/**
	 * Check whether or not the given character is a plus or minus.
	 * @since 1.3
	 * @param operator The character that is to be evaluated.
	 * @return Whether or not the given character a plus or minus sign.
	 */
	public static boolean isAdder(char operator) {
		String operators = "+-";
		if (operators.indexOf(operator) > -1) {
			return true;
		}
		else {
			return false;
		}
	}
	
	/**
	 * Check whether or not the given character is a times, divide, or modulus.
	 * @since 1.3
	 * @param operator The character that is to be evaluated.
	 * @return Whether or not the given character is times, divide, or modulus sign.
	 */
	public static boolean isMultiplier(char operator) {
		String operators = "*/%";
		if (operators.indexOf(operator) > -1) {
			return true;
		}
		else {
			return false;
		}
	}
	
	
	/**
	 * Converts a String into an array that's ready to be processed by Calculator.getElements(ArrayList<String>).
	 * @since 1.4
	 * @param problemString A regular string that represents a mathematical problem.
	 * @return A String ArrayList which alternates between numbers and operators.  
	 */
	private static ArrayList<String> extract(String problemString) {
		
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
		
		return problem;
	}
	
	/**
	 * Converts a String into an array that's ready to be processed by Calculator.solve(ArrayList<ArrayList<String>>).
	 * @since 1.3
	 * @param problemString A regular string that represents a mathematical problem.
	 * @return A 2D String ArrayList in which every every element of the 1st level represents a mathematical element. the strings inside the 2nd level alternate between operators and numbers. 
	 */
	public static ArrayList<ArrayList<String>> compile(String problemString) {
		return getElements(extract(problemString));
	}
	
	/**
	 * Solves the given mathematical problem.
	 * @since 1.3
	 * @param problem The problem to be solved.
	 * @return The solution to the problem.
	 */
	public static double solve(ArrayList<ArrayList<String>> problem) {
		ArrayList<String> firstStageSolution = new ArrayList<String>();
		
		for (ArrayList<String> element : problem) {
			double currentResult = Double.parseDouble(element.get(1));
			
			for (int i = 2; i < element.size(); i++) {
				if (i % 2 == 1) {
					currentResult = Calculator.calculate(currentResult, Double.parseDouble(element.get(i + 1)), element.get(i).charAt(0));
				}
			}
			firstStageSolution.add(element.get(0));
			firstStageSolution.add(currentResult + "");
		}
		
		double currentResult = Double.parseDouble(firstStageSolution.get(1));
		
		for (int i = 2; i < firstStageSolution.size(); i++) {
			if (i % 2 == 0) {
				currentResult = Calculator.calculate(currentResult, Double.parseDouble(firstStageSolution.get(i + 1)), firstStageSolution.get(i).charAt(0));
			}
		}
		
		return currentResult;
	}

	/**
	 * Perform binary mathematical operations. Currently only addition, subtraction, multiplication, division, and modulus are supported.
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
	 * Calculator is a utility class that offers no instance methods. As such, it has no reason to be instantiated.
	 * @since 1.3
	 */
	private Calculator() {
//		Do nothing.
	}
	
	/**
	 * @since 1.4
	 * @param problem
	 * @return
	 */
	private static ArrayList<ArrayList<String>> getElements(ArrayList<String> problem) {
		ArrayList<ArrayList<String>> elements = new ArrayList<ArrayList<String>>();
		
		ArrayList<String> firstElement = new ArrayList<String>();
		firstElement.add("+");
		
		for (int i = 0; i < problem.size(); i++) {
			if (!isAdder(problem.get(i).charAt(0))) {
				firstElement.add(problem.get(i));
			}
			else {
				break;
			}
		}
		
		elements.add(firstElement);
		
//		TODO fix the infinite loop which is the result of the following code:
		
		for (int i = 0; i < problem.size(); i++) {
			if (isAdder(problem.get(i).charAt(0))) {
				ArrayList<String> element = new ArrayList<String>();
				element.add(problem.get(i));
				elements.add(element);
				for (int h = i; h < problem.size(); h++) {
					if (!isAdder(problem.get(h).charAt(0))) {
						element.add(problem.get(h));
					}
					else {
						i = h - 1;
						break;
					}
				}
			}
		}
		return elements;
	}
}
