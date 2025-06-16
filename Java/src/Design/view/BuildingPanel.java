package src.Design.view;

import src.Design.HoverInfoButton;
import src.Design.controller.GameController;
import src.Design.event.EventManager;

import javax.swing.*;
import java.awt.*;
import java.util.Map;

/**
 * 建筑面板类，用于显示和管理游戏中的建筑选项
 */
public class BuildingPanel {
    private JPanel panel;
    private GameController controller;
    private JPanel cartPanel; // 保存货车按钮面板的引用
    
    /**
     * 构造函数
     * @param controller 游戏控制器
     */
    public BuildingPanel(GameController controller) {
        this.controller = controller;
        
        // 初始化面板
        panel = new JPanel();
        panel.setBackground(Color.WHITE);
        panel.setBorder(BorderFactory.createTitledBorder("建筑面板"));
        panel.setVisible(false); // 初始不可见，等待游戏阶段2触发
        
        // 监听游戏阶段变化事件
        controller.getEventManager().addGamePhaseChangeListener(this::onGamePhaseChanged);
        
        // 监听建筑变化事件
        controller.getEventManager().addBuildingChangeListener(this::onBuildingChanged);
    }
    
    /**
     * 获取面板
     * @return 建筑面板
     */
    public JPanel getPanel() {
        return panel;
    }
    
    /**
     * 游戏阶段变化处理
     * @param isPhase2 是否为阶段2
     */
    private void onGamePhaseChanged(boolean isPhase2) {
        if (isPhase2) {
            panel.setVisible(true);
            addBuildingOptions();
        }
    }
    
    /**
     * 添加建筑选项
     */
    private void addBuildingOptions() {
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.setBorder(BorderFactory.createTitledBorder("建筑"));
        
        // 创建小屋按钮及其信息标签的面板
        JPanel hutPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        HoverInfoButton hutButton = new HoverInfoButton("小屋", "木头-100");
        hutPanel.add(hutButton);
        hutPanel.add(hutButton.getInfoLabel());
        panel.add(hutPanel);
        
        // 创建陷阱按钮及其信息标签的面板
        JPanel trapPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        HoverInfoButton trapButton = new HoverInfoButton("陷阱", "木头-10");
        trapPanel.add(trapButton);
        trapPanel.add(trapButton.getInfoLabel());
        panel.add(trapPanel);
        
        // 创建货车按钮及其信息标签的面板
        cartPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        HoverInfoButton cartButton = new HoverInfoButton("货车", "木头-30");
        cartPanel.add(cartButton);
        cartPanel.add(cartButton.getInfoLabel());
        panel.add(cartPanel);
        
        // 为建筑按钮添加动作监听器
        hutButton.addActionListener(e -> controller.buildHut());
        trapButton.addActionListener(e -> controller.buildTrap());
        cartButton.addActionListener(e -> controller.buildCart());
        
        panel.revalidate();
        panel.repaint();
    }
    
    /**
     * 建筑变化处理
     * @param buildings 建筑数量映射
     */
    private void onBuildingChanged(Map<String, Integer> buildings) {
        // 检查是否有货车，如果有则移除货车按钮
        if (buildings.containsKey("货车") && buildings.get("货车") > 0 && cartPanel != null) {
            panel.remove(cartPanel);
            cartPanel = null;
            panel.revalidate();
            panel.repaint();
        }
    }
}