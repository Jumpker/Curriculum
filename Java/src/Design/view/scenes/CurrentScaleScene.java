package src.Design.view.scenes;

import src.Design.CooldownButton;
import src.Design.controller.GameController;

import javax.swing.*;
import java.awt.*;

/**
 * 静谧森林场景类
 */
public class CurrentScaleScene implements Scene {
    private JPanel panel;
    private GameController controller;
    private JPanel activeEventPanel;
    private CooldownButton checkTrapsButton; // 查看陷阱按钮
    
    /**
     * 构造函数
     */
    public CurrentScaleScene(GameController controller) {
        this.controller = controller;
        
        // 初始化面板
        panel = new JPanel(new BorderLayout());
        panel.setBackground(Color.WHITE);
        
        // 初始化组件
        initializeComponents();
    }
    
    /**
     * 初始化组件
     */
    private void initializeComponents() {

        
        // 交互面板 (中央)
        JPanel interactionPanel = new JPanel(new GridLayout(2, 1)); // 两部分
        interactionPanel.setBackground(Color.WHITE);
        interactionPanel.setBorder(BorderFactory.createTitledBorder("交互面板"));
        
        activeEventPanel = new JPanel();
        activeEventPanel.setBackground(Color.WHITE);
        activeEventPanel.setBorder(BorderFactory.createTitledBorder("主动事件"));
        interactionPanel.add(activeEventPanel);
        
        JPanel laborDistributionPanel = new JPanel();
        laborDistributionPanel.setBackground(Color.WHITE);
        laborDistributionPanel.setBorder(BorderFactory.createTitledBorder("人员分工"));
        interactionPanel.add(laborDistributionPanel);
        
        panel.add(interactionPanel, BorderLayout.CENTER);
    }
    
    /**
     * 为第二阶段更新场景
     */
    public void updateForPhase2() {
        // 添加"伐木"按钮
        CooldownButton chopWoodButton = new CooldownButton("伐木", 15); // 15秒冷却
        activeEventPanel.add(chopWoodButton);
        chopWoodButton.addActionListener(e -> {
            chopWoodButton.startCooldown();
            controller.chopWood();
        });
        
        // 创建"查看陷阱"按钮（初始隐藏）
        checkTrapsButton = new CooldownButton("查看陷阱", 30); // 30秒冷却
        checkTrapsButton.setVisible(false); // 初始隐藏
        activeEventPanel.add(checkTrapsButton);
        checkTrapsButton.addActionListener(e -> {
            checkTrapsButton.startCooldown();
            controller.checkTraps();
        });
        
        // 监听资源变化以更新陷阱按钮可见性
        controller.getEventManager().addResourceChangeListener(this::updateTrapButtonVisibility);
        
        activeEventPanel.revalidate();
        activeEventPanel.repaint();
    }
    
    @Override
    public JPanel getPanel() {
        return panel;
    }
    
    @Override
    public void update() {
        // 更新场景状态
    }
    

    
    /**
     * 更新陷阱按钮可见性
     * @param resources 资源映射
     */
    private void updateTrapButtonVisibility(java.util.Map<String, Integer> resources) {
        if (checkTrapsButton != null) {
            int trapCount = controller.getTrapManager().getTrapCount();
            boolean shouldShow = trapCount > 0;
            if (checkTrapsButton.isVisible() != shouldShow) {
                checkTrapsButton.setVisible(shouldShow);
                activeEventPanel.revalidate();
                activeEventPanel.repaint();
            }
        }
    }
}