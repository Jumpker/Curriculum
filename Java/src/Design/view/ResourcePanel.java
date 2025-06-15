package src.Design.view;

import src.Design.controller.GameController;
import src.Design.event.EventManager;

import javax.swing.*;
import java.awt.*;
import java.util.Map;

/**
 * 资源面板类，用于显示游戏中的资源信息
 */
public class ResourcePanel {
    private JPanel panel;
    private GameController controller;
    
    /**
     * 构造函数
     * @param controller 游戏控制器
     */
    public ResourcePanel(GameController controller) {
        this.controller = controller;
        
        // 初始化面板
        panel = new JPanel();
        panel.setBackground(Color.WHITE);
        panel.setBorder(BorderFactory.createTitledBorder("资源面板"));
        panel.setPreferredSize(new Dimension(250, panel.getPreferredSize().height));
        panel.setVisible(false); // 初始不可见，等待游戏阶段2触发
        
        // 监听资源变化事件
        controller.getEventManager().addResourceChangeListener(this::updateResources);
        
        // 监听游戏阶段变化事件
        controller.getEventManager().addGamePhaseChangeListener(this::onGamePhaseChanged);
    }
    
    /**
     * 获取面板
     * @return 资源面板
     */
    public JPanel getPanel() {
        return panel;
    }
    
    /**
     * 更新资源显示
     * @param resources 资源映射
     */
    private void updateResources(Map<String, Integer> resources) {
        panel.removeAll();
        for (Map.Entry<String, Integer> entry : resources.entrySet()) {
            panel.add(new JLabel(entry.getKey() + ": " + entry.getValue()));
        }
        panel.revalidate();
        panel.repaint();
    }
    
    /**
     * 游戏阶段变化处理
     * @param isPhase2 是否为阶段2
     */
    private void onGamePhaseChanged(boolean isPhase2) {
        if (isPhase2) {
            panel.setVisible(true);
        }
    }
}