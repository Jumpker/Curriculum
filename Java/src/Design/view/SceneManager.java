package src.Design.view;

import src.Design.controller.GameController;
import src.Design.view.scenes.CurrentScaleScene;
import src.Design.view.scenes.FireRoomScene;
import src.Design.view.scenes.LongJourneyScene;
import src.Design.view.scenes.Scene;

import javax.swing.*;
import java.awt.*;

/**
 * 场景管理器类，负责管理游戏中的不同场景
 */
public class SceneManager {
    public static final String FIRE_ROOM_SCENE = "FireRoom";
    public static final String CURRENT_SCALE_SCENE = "CurrentScale";
    public static final String LONG_JOURNEY_SCENE = "LongJourney";
    
    private JPanel mainContentPanel;
    private CardLayout cardLayout;
    private GameController controller;
    
    private FireRoomScene fireRoomScene;
    private CurrentScaleScene currentScaleScene;
    private LongJourneyScene longJourneyScene;
    
    private ResourcePanel resourcePanel;
    private BuildingPanel buildingPanel;
    
    /**
     * 构造函数
     * @param controller 游戏控制器
     */
    public SceneManager(GameController controller) {
        this.controller = controller;
        
        // 初始化卡片布局和主内容面板
        cardLayout = new CardLayout();
        mainContentPanel = new JPanel(cardLayout);
        mainContentPanel.setBackground(Color.WHITE);
        
        // 创建资源面板和建筑面板
        resourcePanel = new ResourcePanel(controller);
        buildingPanel = new BuildingPanel(controller);
        
        // 初始化场景
        initializeScenes();
        
        // 监听游戏阶段变化
        controller.getEventManager().addGamePhaseChangeListener(this::onGamePhaseChanged);
    }
    
    /**
     * 初始化场景
     */
    private void initializeScenes() {
        // 创建场景
        fireRoomScene = new FireRoomScene(controller);
        currentScaleScene = new CurrentScaleScene(controller);
        longJourneyScene = new LongJourneyScene();
        
        // 添加场景到卡片布局
        mainContentPanel.add(fireRoomScene.getPanel(), FIRE_ROOM_SCENE);
        mainContentPanel.add(currentScaleScene.getPanel(), CURRENT_SCALE_SCENE);
        mainContentPanel.add(longJourneyScene.getPanel(), LONG_JOURNEY_SCENE);
        
        // 默认显示生火间场景
        cardLayout.show(mainContentPanel, FIRE_ROOM_SCENE);
    }
    
    /**
     * 获取主内容面板
     * @return 主内容面板
     */
    public JPanel getMainContentPanel() {
        return mainContentPanel;
    }
    
    /**
     * 显示指定场景
     * @param sceneName 场景名称
     */
    public void showScene(String sceneName) {
        cardLayout.show(mainContentPanel, sceneName);
        
        // 更新当前场景
        Scene currentScene = getCurrentScene(sceneName);
        if (currentScene != null) {
            currentScene.update();
        }
    }
    
    /**
     * 获取当前场景
     * @param sceneName 场景名称
     * @return 当前场景
     */
    private Scene getCurrentScene(String sceneName) {
        switch (sceneName) {
            case FIRE_ROOM_SCENE:
                return fireRoomScene;
            case CURRENT_SCALE_SCENE:
                return currentScaleScene;
            case LONG_JOURNEY_SCENE:
                return longJourneyScene;
            default:
                return null;
        }
    }
    
    /**
     * 游戏阶段变化处理
     * @param isPhase2 是否为阶段2
     */
    private void onGamePhaseChanged(boolean isPhase2) {
        if (isPhase2) {
            // 更新当前规模场景，添加伐木按钮
            currentScaleScene.updateForPhase2();
        }
    }
    
    /**
     * 获取资源面板
     * @return 资源面板
     */
    public ResourcePanel getResourcePanel() {
        return resourcePanel;
    }
    
    /**
     * 获取建筑面板
     * @return 建筑面板
     */
    public BuildingPanel getBuildingPanel() {
        return buildingPanel;
    }
}