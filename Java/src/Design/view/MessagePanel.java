package src.Design.view;

import src.Design.controller.GameController;

import javax.swing.*;
import java.awt.*;

/**
 * 消息面板类，负责显示游戏消息
 */
public class MessagePanel {
    private JPanel panel;
    private GameController controller;
    
    /**
     * 构造函数
     */
    public MessagePanel(GameController controller) {
        this.controller = controller;
        
        // 初始化面板
        panel = new JPanel();
        panel.setBackground(Color.WHITE);
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        
        // 注册消息监听器
        controller.getEventManager().addMessageListener(this::addMessage);
    }
    
    /**
     * 添加消息
     */
    public void addMessage(String message) {
        JLabel messageLabel = new JLabel(message);
        messageLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        panel.add(messageLabel, 0); // 添加到顶部
        panel.revalidate();
        panel.repaint();
        
        // 75秒后移除消息
        Timer timer = new Timer(75000, e -> {
            panel.remove(messageLabel);
            panel.revalidate();
            panel.repaint();
        });
        timer.setRepeats(false);
        timer.start();
    }
    
    /**
     * 获取面板
     */
    public JPanel getPanel() {
        return panel;
    }
}