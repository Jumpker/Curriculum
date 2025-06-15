package src.Design.view.scenes;

import javax.swing.JPanel;

/**
 * 场景接口，所有游戏场景都应实现此接口
 */
public interface Scene {
    /**
     * 获取场景面板
     */
    JPanel getPanel();
    
    /**
     * 更新场景
     */
    void update();
}