package src.lesson5;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Circle {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JPanel的绘制示例");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400); // 增加窗口大小以便移动

        new_panel panel = new new_panel();
        frame.add(panel);

        // 使面板可聚焦以接收键盘事件
        panel.setFocusable(true);
        panel.requestFocusInWindow();

        // 使用Timer进行平滑刷新
        Timer timer = new Timer(5, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                panel.repaint(); // 每10毫秒重绘一次面板
            }
        });
        timer.start();

        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
    }
}

class new_panel extends JPanel implements KeyListener {
    int x = 50, y = 50; // 圆的初始位置
    int diameter = 50; // 圆的直径
    int moveSpeed = 10; // 移动速度

    public new_panel() {
        // 添加键盘监听器
        addKeyListener(this);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.RED);
        // 绘制圆
        g.fillOval(x, y, diameter, diameter);
        g.drawString("使用方向键移动圆", 10, 20);
    }

    // KeyListener methods
    @Override
    public void keyTyped(KeyEvent e) {
        // 不需要实现
    }

    @Override
    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        switch (keyCode) {
            case KeyEvent.VK_LEFT:
                x -= moveSpeed;
                break;
            case KeyEvent.VK_RIGHT:
                x += moveSpeed;
                break;
            case KeyEvent.VK_UP:
                y -= moveSpeed;
                break;
            case KeyEvent.VK_DOWN:
                y += moveSpeed;
                break;
        }
        // 边界检查 (可选，防止圆移出窗口)
        if (x < 0) x = 0;
        if (x > getWidth() - diameter) x = getWidth() - diameter;
        if (y < 0) y = 0;
        if (y > getHeight() - diameter) y = getHeight() - diameter;

        // 移除这里的repaint()，因为Timer会负责刷新
        // repaint();
    }

    @Override
    public void keyReleased(KeyEvent e) {
        // 不需要实现
    }
}