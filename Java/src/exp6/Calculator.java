package src.exp6;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator extends JFrame implements ActionListener {

    private JTextField displayField;
    private String currentInput = "";
    private double result = 0;
    private String lastOperator = "";
    private boolean startNewNumber = true;

    public Calculator() {
        setTitle("计算器");
        setSize(300, 400);//计算器窗口大小
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // 窗口居中

        // 显示区域
        displayField = new JTextField("0");//新建显示框对象，刚打开计算器时默认显示为0
        displayField.setFont(new Font("Arial", Font.PLAIN, 24));//定义字体和字号
        add(displayField, BorderLayout.NORTH);//显示框放在窗口最上方

        // 按钮面板
        JPanel buttonPanel = new JPanel();//用panel布局面板放置按钮
        buttonPanel.setLayout(new GridLayout(5, 4, 5, 5)); // 5行4列，间距5像素

        String[] buttonLabels = {
                "C", "/", "*", "D",
                "7", "8", "9", "-",
                "4", "5", "6", "+",
                "1", "2", "3", "=",
                "0", "."
        };

        for (int i = 0; i < buttonLabels.length; i++) {
            String label = buttonLabels[i];
            JButton button = new JButton(label);
            button.setFont(new Font("Arial", Font.PLAIN, 18));
            button.addActionListener(this);
            buttonPanel.add(button);
        }

        add(buttonPanel, BorderLayout.CENTER);//按钮面板放在窗口最中间
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (command.matches("[0-9]") || (command.equals(".") && !currentInput.contains("."))) {
            if (startNewNumber) {//如果是输入新的数字，则将输入框清空
                currentInput = command;
                startNewNumber = false;
            } else {
                currentInput += command;
            }
            displayField.setText(currentInput);
        } else if (command.matches("[+\\-*/=]")) {
            if (!currentInput.isEmpty()) {
                calculate(Double.parseDouble(currentInput));
            }
            lastOperator = command;
            startNewNumber = true;
        } else if (command.equals("C")) {
            currentInput = "";
            result = 0;
            lastOperator = "";
            startNewNumber = true;
            displayField.setText("0");
        } else if (command.equals("DEL")) {
            if (currentInput.length() > 0) {
                currentInput = currentInput.substring(0, currentInput.length() - 1);
                if (currentInput.isEmpty()) {
                    displayField.setText("0");
                    startNewNumber = true;
                } else {
                    displayField.setText(currentInput);
                }
            }
        }
    }

    private void calculate(double number) {//计算的具体实现函数
        if (lastOperator.isEmpty() || lastOperator.equals("=")) {
            result = number;
        } else if (lastOperator.equals("+")) {
            result += number;
        } else if (lastOperator.equals("-")) {
            result -= number;
        } else if (lastOperator.equals("*")) {
            result *= number;
        } else if (lastOperator.equals("/")) {
            if (number != 0) {
                result /= number;
            } else {
                displayField.setText("Error");
                currentInput = "";
                result = 0;
                lastOperator = "";
                startNewNumber = true;
                return;
            }
        }
        displayField.setText(String.valueOf(result));
        currentInput = String.valueOf(result);
    }

    public static void main(String[] args) {
        new Calculator().setVisible(true);
    }
}