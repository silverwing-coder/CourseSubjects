<h6>ver. Apr-2024</h6>
<h3>CIS 112 GUI Demo - SimpleCalucalator </h3>

---

```java

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator implements ActionListener{

	JFrame frame;
	JTextField textField;
	JButton[] numberButtons = new JButton[10];
	JButton[] functionButtons = new JButton[8];
	JButton addButton, subButton, mulButton, divButton;
	JButton decButton, equButton, delButton, clrButton;
	JPanel panel;

	Font myFont = new Font("Calibri", Font.BOLD, 30);

	double num1 = 0, num2 = 0, result = 0;
	char operator;

	public SimpleCalculator(){
		/* initialize frame */
		frame = new JFrame("Simple Calculator");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(420, 550);
		frame.setLayout(null);

		/* initialize textField */
		textField = new JTextField();
		textField.setBounds(50, 20, 300, 50); // starting point x and y, width, height
		textField.setFont(myFont);
		textField.setEditable(false); // not able to type in
//		textField.setText("0");
		textField.setHorizontalAlignment(JTextField.RIGHT);
		frame.add(textField);

		/* initialize number buttons  */
		for(int i = 0; i < numberButtons.length; ++i) {
			numberButtons[i] = new JButton(String.valueOf(i));
			numberButtons[i].addActionListener(this);
			numberButtons[i].setFont(myFont);
//			numberButtons[i].setFocusable(false);
		}

		/* initialize function buttons  */
		addButton = new JButton("+");
		subButton = new JButton("-");
		mulButton = new JButton("*");
		divButton = new JButton("/");
		decButton = new JButton(".");
		equButton = new JButton("=");
		delButton = new JButton("DEL");
		clrButton = new JButton("CLR");
		functionButtons[0] = addButton;
		functionButtons[1] = subButton;
		functionButtons[2] = mulButton;
		functionButtons[3] = divButton;
		functionButtons[4] = decButton;
		functionButtons[5] = equButton;
		functionButtons[6] = delButton;
		functionButtons[7] = clrButton;

		for(int i = 0; i < functionButtons.length; ++i) {
			functionButtons[i].addActionListener(this);
			functionButtons[i].setFont(myFont);
			functionButtons[i].setFocusable(false);
		}

		/* add to frame */
		delButton.setBounds(50, 430, 145, 50);
		clrButton.setBounds(205, 430, 145, 50);

		/* add to frame */
		frame.add(delButton);
		frame.add(clrButton);

		/* initialize panel  */
		panel = new JPanel();
		panel.setBounds(50, 100, 300, 300);
		panel.setLayout(new GridLayout(4, 4, 10, 10));
		panel.setBackground(Color.LIGHT_GRAY);

		/* add buttons to panel  */
		panel.add(numberButtons[1]);
		panel.add(numberButtons[2]);
		panel.add(numberButtons[3]);
		panel.add(addButton);
		panel.add(numberButtons[4]);
		panel.add(numberButtons[5]);
		panel.add(numberButtons[6]);
		panel.add(subButton);
		panel.add(numberButtons[7]);
		panel.add(numberButtons[8]);
		panel.add(numberButtons[9]);
		panel.add(mulButton);
		panel.add(decButton);
		panel.add(numberButtons[0]);
		panel.add(equButton);
		panel.add(divButton);

		/* add to frame */
		frame.add(panel);

		frame.setVisible(true);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		SimpleCalculator calc = new SimpleCalculator();

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		for(int i = 0; i < 10; i++) {
			if(e.getSource() == numberButtons[i]) {
				textField.setText(textField.getText().concat(String.valueOf(i)));
			}
		}

		if(e.getSource() == decButton) {
			textField.setText(textField.getText().concat("."));
		}

		if(e.getSource() == addButton) {
			num1 = Double.parseDouble(textField.getText());
			operator = '+';
			textField.setText("");
		}

		if(e.getSource() == subButton) {
			num1 = Double.parseDouble(textField.getText());
			operator = '-';
			textField.setText("");
		}

		if(e.getSource() == mulButton) {
			num1 = Double.parseDouble(textField.getText());
			operator = '*';
			textField.setText("");
		}

		if(e.getSource() == divButton) {
			num1 = Double.parseDouble(textField.getText());
			operator = '/';
			textField.setText("");
		}

		if(e.getSource() == equButton) {
			num2 = Double.parseDouble(textField.getText());
			switch(operator) {
			case '+':
				result = num1 + num2;
				break;
			case '-':
				result = num1 - num2;
				break;
			case '*':
				result = num1 * num2;
				break;
			case '/':
				result = num1 / num2;
				break;
			}
//			result = Math.round(result);
			String strResult = String.format("%.2f", result);
			textField.setText(strResult);
		}

		if(e.getSource() == clrButton) {
			textField.setText("");
		}

		if(e.getSource() == delButton) {
			String string = textField.getText();
			if(!string.equals("")) {
				textField.setText(string.substring(0, string.length()-1));
			}
		}
	}

}


```
