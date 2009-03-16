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
	/**
	 * The file chooser dialogue.
	 */
	private JFileChooser fc = new JFileChooser();
	
	/**
	 * Stores the file that is currently being scanned.
	 */
	private File file;
	
	/**
	 * Holds the entire GUI, with the exception of the status bar.
	 */
	private JPanel panel = new JPanel();
	
	/**
	 * Opens a file for scanning.
	 */
	private JButton open = new JButton("Open");
	
	/**
	 * Opens a report file and displays it's contents. (CSV format).
	 */
	private JButton load = new JButton("Load");
	
	/**
	 * Saves the report as a CSV file.
	 */
	private JButton save = new JButton("Save");
	
	/**
	 * Performs the scan.
	 */
	private JButton scan = new JButton("Scan");
	
	/**
	 * Specifies the characters that will be counted.
	 */
	private JTextField characters = new JTextField("abcdefghijklmnopqrstuvwxyz");
	
	/**
	 * Specified whether or not the count is case sensitive.
	 */
	private JCheckBox caseSensitive = new JCheckBox("Case sensitive", false);
	
	/**
	 * The names of the columns in the display table.
	 */
	private String[] columnNames = {"Character", "Count", "Percentage"};
	
	/**
	 * The default data that appears in the display table.
	 */
	Object[][] data = {{"", "", ""}};
	
	/**
	 * The table in which the results of the scan are displayed.
	 */
	private JTable display = new JTable(data, columnNames);
	
	private JPanel statusBar = new JPanel();
	
	/**
	 * Displays messages.
	 */
	private JLabel message = new JLabel(" ");
	
	/**
	 * A Cached reference to the MainWindow's conntent pane.
	 */
	private Container contentPane = this.getContentPane();
	
	/**
	 * Construct a new instance of window, and scan the specified file with the default characters.
	 * @param path The file that will be scanned.
	 */
	public MainWindow(String path) {
		this();
		this.file = new File(path);
		this.message.setText("Opened " + file.getAbsolutePath());
		scan();
	}
	
	/**
	 * Construct a new instance of window, and scan the specified file with the specified characters.
	 * @param path The file that will be scanned.
	 * @param characters The characters that will be counted.
	 */
	public MainWindow(String path, String characters) {
		this();
		this.file = new File(path);
		this.message.setText("Opened " + file.getAbsolutePath());
		this.characters.setText(characters);
		scan();
	}
	
	/**
	 * Sets up the application's GUI.
	 *
	 */
	public MainWindow() {
		
//		Laying out the widgets in the panel:
		
		panel.setLayout(new GridBagLayout());
		GridBagConstraints panelConstraints = new GridBagConstraints();
		Insets panelInsets = new Insets(2, 2, 2, 2);
		panelConstraints.insets = panelInsets;
		
		panelConstraints.gridx = 0;
		panelConstraints.gridy = 0;
		panelConstraints.weightx = 0;
		panelConstraints.weighty = 0;
		panelConstraints.anchor = GridBagConstraints.LINE_START;
		panelConstraints.fill = GridBagConstraints.NONE;
		panel.add(open, panelConstraints);
		
		panelConstraints.gridx = 1;
		panel.add(load, panelConstraints);
		
		panelConstraints.gridx = 2;
		panel.add(save, panelConstraints);
		
		panelConstraints.gridx = 3;
		panel.add(scan, panelConstraints);
		
		panelConstraints.gridx = 4;
		panelConstraints.weightx = 1;
		panelConstraints.fill = GridBagConstraints.BOTH;
		panel.add(characters, panelConstraints);
		
		panelConstraints.gridx = 5;
		panelConstraints.weightx = 0;
		panelConstraints.fill = GridBagConstraints.NONE;
		panel.add(caseSensitive, panelConstraints);
		
		panelConstraints.gridwidth = 6;
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
					message.setText("Opened " + file.getAbsolutePath());
				}
			}
		});
		
		load.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (fc.showSaveDialog(contentPane) == JFileChooser.APPROVE_OPTION) {
					File file = fc.getSelectedFile();
					
					try {
						DefaultTableModel tm = new DefaultTableModel();
						tm.setColumnIdentifiers(columnNames);
						Scanner in = new Scanner(file);
						
						while (in.hasNextLine()) {
							String values = in.nextLine();
							tm.addRow(values.split(","));
						}
						
						display.setModel(tm);
						message.setText("Loaded report: " + file.getAbsolutePath());
					}
					catch (FileNotFoundException fnfe) {
						message.setText("Load failed: the specified file was not found");
					}
				}
			}
		});
		
		save.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (fc.showSaveDialog(contentPane) == JFileChooser.APPROVE_OPTION) {
					File file = fc.getSelectedFile();
					int rows = display.getModel().getRowCount();
					
					try {
						PrintWriter out = new PrintWriter(file);
						
						for (int r = 0; r < rows; r++) {
							out.print(display.getModel().getValueAt(r, 0) + ",");
							out.print(display.getModel().getValueAt(r, 1) + ",");
							out.println(display.getModel().getValueAt(r, 2));
						}
						
						out.flush();
						message.setText("Saved report: " + file.getAbsolutePath());
					}
					catch (FileNotFoundException fnfe) {
						message.setText("Save failed: the specified file was not found");
					}
				}
			}
		});
		
		scan.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				scan();
			}
		});
		
//		Setting tooltips:
		
		characters.setToolTipText("The characters that will be counted in this scan");
		open.setToolTipText("Open a file for scanning");
		load.setToolTipText("Display the results of a previus scan");
		save.setToolTipText("Save the results of this scan");
		scan.setToolTipText("Perform the scan and display the results on screen");
		caseSensitive.setToolTipText("Make the scan case-sensitive");
		
//		Setting keyboard shortcuts:
		
		open.setMnemonic(KeyEvent.VK_O);
		caseSensitive.setMnemonic(KeyEvent.VK_A);
		load.setMnemonic(KeyEvent.VK_L);
		save.setMnemonic(KeyEvent.VK_V);
		scan.setMnemonic(KeyEvent.VK_S);
		
//		Laying out the widgets in the status bar:
		
		statusBar.setLayout(new FlowLayout(FlowLayout.LEADING));
		statusBar.add(message);
		
//		Laying out the widgets in the content pane:
		
		contentPane.add(panel, BorderLayout.CENTER);
		contentPane.add(statusBar, BorderLayout.SOUTH);
		
//		Window setup:
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setTitle("Character Counter");
		this.setSize(new Dimension(600, 500));
		this.setLocationRelativeTo(this);
		this.setVisible(true);
	}
	
	/**
	 * @param args The first argument is the path of a file the user wishes to analyze. The second argument is the list of characters the user wishes to count.
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
	 * Counts the number of occurances of the specified characters in the specified file and displays the results.
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
				this.message.setText("Finished scanning " + file.getAbsolutePath());
			}
			catch (FileNotFoundException e) {
				this.message.setText("Scan failed: the specified file was not found");
			}
		}
		else {
			this.message.setText("Please select a file");
		}
	}
}
