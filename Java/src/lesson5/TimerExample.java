package src.lesson5;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class TimerExample {
    public static void main(String[] args) {
        JPanel panel = new JPanel(){
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.drawString("Hello World", 50, 50);
            }
        };
// 修正语法错误，补充完整 Lambda 表达式的语法结构
// 由于 button 未定义，这里先创建一个 JButton 实例并添加动作监听器
        JButton button = new JButton("Click me");
// 由于 label 未定义，先创建一个 JLabel 实例并在动作监听器中使用
JLabel label = new JLabel("Initial Text");
panel.add(label); // 将标签添加到面板上
// 导入缺失的 ActionEvent 类
button.addActionListener (e -> label.setText("Button clicked!"));
    }

}