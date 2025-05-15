package src.lesson5;

import javax.swing.*;

public class GUI {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Hello GUI");
        frame.setSize(400, 300); // 设置窗口大小
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // 设置关闭操作
        frame.setVisible(true); // 显示窗口
        JButton button = new JButton("Click Me!");
        frame.add(button);
        frame.setVisible(true);
    }
}
