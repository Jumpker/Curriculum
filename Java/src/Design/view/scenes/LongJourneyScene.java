package src.Design.view.scenes;

import javax.swing.*;
import java.awt.*;

/**
 * 漫漫尘途场景类
 */
public class LongJourneyScene implements Scene {
    private JPanel panel;
    
    /**
     * 构造函数
     */
    public LongJourneyScene() {
        // 初始化面板
        panel = new JPanel();
        panel.setBackground(Color.WHITE);
        panel.add(new JLabel("漫漫尘途 敬请期待."));
    }
    
    @Override
    public JPanel getPanel() {
        return panel;
    }
    
    @Override
    public void update() {
        // 暂无需更新的内容
    }
}