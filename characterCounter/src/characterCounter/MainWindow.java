package characterCounter;

import java.awt.*;
import java.awt.event.*;
import java.net.URL;
import java.util.*;
import javax.swing.*;
import javax.swing.table.*;
import java.io.*;

public class MainWindow extends JFrame {
	private JFileChooser fc = new JFileChooser();
	private File file;
	
	private JPanel panel = new JPanel();
	private JPanel[] toolbars = new JPanel[2];
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
	private JLabel progress = new JLabel(" ");
	
	private Container contentPane = this.getContentPane();
	
	public MainWindow() {
		
//		Main panel setup:
		
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
		open.setMnemonic(KeyEvent.VK_O);
		panel.add(open, panelConstraints);
		
		panelConstraints.gridx = 1;
		fileName.setEditable(false);
		panel.add(fileName, panelConstraints);
		
		panelConstraints.gridy = 1;
		panelConstraints.gridx = 0;
		charLabel.setLabelFor(characters);
		charLabel.setDisplayedMnemonic(KeyEvent.VK_C);
		panel.add(charLabel, panelConstraints);
		
		panelConstraints.gridx = 1;
		panelConstraints.weightx = 1;
		panel.add(characters, panelConstraints);
		
		panelConstraints.gridy = 2;
		panelConstraints.gridx = 0;
		panelConstraints.weightx = 0;
		caseSensitive.setMnemonic(KeyEvent.VK_A);
		panel.add(caseSensitive, panelConstraints);
		
		panelConstraints.gridx = 1;
		panelConstraints.anchor = GridBagConstraints.LINE_END;
		panelConstraints.fill = GridBagConstraints.NONE;
		scan.setMnemonic(KeyEvent.VK_S);
		panel.add(scan, panelConstraints);
		
		panelConstraints.gridwidth = 2;
		panelConstraints.gridx = 0;
		panelConstraints.gridy = GridBagConstraints.RELATIVE;
		panelConstraints.fill = GridBagConstraints.BOTH;
		panelConstraints.weightx = 1;
		panelConstraints.weighty = 1;
		display.setEnabled(false);
		panel.add(new JScrollPane(display), panelConstraints);
		
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
		
//		Status-bar setup:
		
		statusBar.setLayout(new FlowLayout(FlowLayout.LEADING));
		statusBar.add(progress);
		
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
		
		new MainWindow();
	}
	
	private static Image getImage(String path) {
        URL imgURL = MainWindow.class.getResource(path);
        if (imgURL != null) {
            return new ImageIcon(imgURL).getImage();
        } else {
            return null;
        }
    }
	
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
				this.progress.setText("Scan complete");
			}
			catch (FileNotFoundException e) {
				this.progress.setText("IO error: file not found");
			}
		}
		else {
			this.progress.setText("Please select a file");
		}
	}
}
