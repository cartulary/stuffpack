/*
 * Copyright © 2009 Gerald Isaac Schwarz
 * LICENSE
 * Permission to use, copy, modify and distribute this software and its documentation is hereby granted, provided that both the copyright notice and this permission notice appear in all copies of the software, derivative works or modified versions, and any portions thereof, and that both notices appear in supporting documentation.
 * 
 * DISCLAIMER
 * This software is provided "as is" with no warranty, liability, or any implication thereof.
 */

package characterCounter;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.table.*;
import java.io.*;

/**
 * This is a program that counts the number of occurances of the specified characters in the specified text document.
 * @author yitz
 *
 */
public class MainWindow extends JFrame {
	private JFileChooser fc = new JFileChooser();
	private File file;
	
	private JPanel panel = new JPanel();
	private JButton open = new JButton("Open");
	private JTextField fileName = new JTextField();
	private JButton scan = new JButton("Scan");
	private JLabel charLabel = new JLabel("Counted characters:");
	private JTextField characters = new JTextField("abcdefghijklmnopqrstuvwxyz");
	private JCheckBox caseSensitive = new JCheckBox("Case sensitive", false);
	
	private String[] columnNames = {"Character", "Count", "Percentage"};
	Object[][] data = {{"", "", ""}};
	private JTable display = new JTable(data, columnNames);
	
	private JPanel statusBar = new JPanel();
	private JLabel message = new JLabel(" ");
	
	private Container contentPane = this.getContentPane();
	
	public MainWindow(String path) {
		this();
		this.file = new File(path);
		this.fileName.setText(file.getAbsolutePath());
		scan();
	}
	
	public MainWindow(String path, String characters) {
		this();
		this.file = new File(path);
		this.fileName.setText(file.getAbsolutePath());
		this.characters.setText(characters);
		scan();
	}
	
	public MainWindow() {
		
//		Laying out the widgets on the screen:
		
		panel.setLayout(new GridBagLayout());
		GridBagConstraints panelConstraints = new GridBagConstraints();
		Insets panelInsets = new Insets(2, 2, 2, 2);
		panelConstraints.insets = panelInsets;
		
		panelConstraints.gridx = 0;
		panelConstraints.gridy = 0;
		panelConstraints.weightx = 0;
		panelConstraints.weighty = 0;
		panelConstraints.anchor = GridBagConstraints.LINE_START;
		panelConstraints.fill = GridBagConstraints.BOTH;
		panel.add(open, panelConstraints);
		
		panelConstraints.gridx = 1;
		fileName.setEnabled(false);
		panel.add(fileName, panelConstraints);
		
		panelConstraints.gridy = 1;
		panelConstraints.gridx = 0;
		charLabel.setLabelFor(characters);
		panel.add(charLabel, panelConstraints);
		
		panelConstraints.gridx = 1;
		panelConstraints.weightx = 1;
		panel.add(characters, panelConstraints);
		
		panelConstraints.gridy = 2;
		panelConstraints.gridx = 0;
		panelConstraints.weightx = 0;
		panel.add(caseSensitive, panelConstraints);
		
		panelConstraints.gridx = 1;
		panelConstraints.anchor = GridBagConstraints.LINE_END;
		panelConstraints.fill = GridBagConstraints.NONE;
		panel.add(scan, panelConstraints);
		
		panelConstraints.gridwidth = 2;
		panelConstraints.gridx = 0;
		panelConstraints.gridy = GridBagConstraints.RELATIVE;
		panelConstraints.fill = GridBagConstraints.BOTH;
		panelConstraints.weightx = 1;
		panelConstraints.weighty = 1;
		display.setEnabled(false);
		panel.add(new JScrollPane(display), panelConstraints);
		
//		Setting action listeners:
		
		open.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (fc.showOpenDialog(contentPane) == JFileChooser.APPROVE_OPTION) {
					file = fc.getSelectedFile();
					fileName.setText(file.getAbsolutePath());
				}
			}
		});
		
		scan.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				scan();
			}
		});
		
//		Setting keyboard shortcuts:
		
		open.setMnemonic(KeyEvent.VK_O);
		charLabel.setDisplayedMnemonic(KeyEvent.VK_C);
		caseSensitive.setMnemonic(KeyEvent.VK_A);
		scan.setMnemonic(KeyEvent.VK_S);
		
//		Status-bar setup:
		
		statusBar.setLayout(new FlowLayout(FlowLayout.LEADING));
		statusBar.add(message);
		
//		Content pane setup:
		
		contentPane.add(panel, BorderLayout.CENTER);
		contentPane.add(statusBar, BorderLayout.SOUTH);
		
//		Window setup:
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setTitle("Character Counter");
		this.setSize(new Dimension(400, 500));
		this.setLocationRelativeTo(this);
		this.setVisible(true);
	}
	
	/**
	 * @param args The first argument is the path of a file the user wishes to analyze.
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
		
		if (args.length == 1) {
			new MainWindow(args[0]);
		}
		else if (args.length > 1) {
			new MainWindow(args[0], args[1]);
		}
		else {
			new MainWindow();
		}
	}
	
	/**
	 * Counts the number of occurances of the characters in the file.
	 * @return An array which stores the results per character.
	 * @throws FileNotFoundException
	 */
	public int[] getCount() throws FileNotFoundException {
		String chars = characters.getText();
		boolean caseSensitive = this.caseSensitive.isSelected();
		int[]  count = new int[chars.length()];
		Scanner sc = new Scanner(file);
		
		while (sc.hasNextLine()) {
			String text = sc.nextLine();
			
			for (int i = 0; i < text.length(); i++) {
				String currentChar = text.charAt(i) + "";
				
				for (int h = 0; h < chars.length(); h++) {
					if (caseSensitive == true) {
						if (currentChar.equals(chars.charAt(h) + "")) {
							count[h]++;
							break;
						}
					}
					else {
						if (currentChar.equalsIgnoreCase(chars.charAt(h) + "")) {
							count[h]++;
							break;
						}
					}
				}
			}
		}
		
		return count;
	}
	
	/**
	 * Counts the characters in file and displays the results.
	 *
	 */
	public void scan() {
		if (file != null) {
			String chars = characters.getText();
			int[] results;
			int total = 0;
			
			try {
				results = getCount();
				DefaultTableModel tm = new DefaultTableModel();
				tm.setColumnIdentifiers(columnNames);
				
				for (int current : results) {
					total += current;
				}
				for (int i = 0; i < results.length; i++) {
					double percent = ((double)results[i] / total) * 100;
					tm.addRow(new Object[] {chars.charAt(i), results[i], String.format("%.1f", percent)});
				}
				
				display.setModel(tm);
				this.message.setText("Scan complete");
			}
			catch (FileNotFoundException e) {
				this.message.setText("IO error: file not found");
			}
		}
		else {
			this.message.setText("Please select a file");
		}
	}
}
