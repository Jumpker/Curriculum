package src.Design;

import src.Design.controller.GameController;
import src.Design.event.EventManager;
import src.Design.model.GameModel;
import src.Design.view.MessagePanel;
import src.Design.view.SceneManager;

import javax.swing.*;
import java.awt.*;

/**
 * 生火间游戏主类
 */
public class FireRoomGame extends JFrame {
    private GameModel model;
    private EventManager eventManager;
    private GameController controller;
    private SceneManager sceneManager;
    private MessagePanel messagePanel;
    private JButton currentScaleButton;
    private JButton longJourneyButton; // 添加为成员变量
    
    /**
     * 构造函数
     */
    public FireRoomGame() {
        // 设置窗口属性
        setTitle("A Dark Room");
        setSize(1000, 700);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // 窗口居中
        
        // 设置所有组件的白色背景和黑色前景
        setUIDefaults();
        
        // 设置布局
        setLayout(new BorderLayout());
        
        // 初始化MVC组件
        initializeMVCComponents();
        
        // 初始化UI组件
        initializeUIComponents();
        
        // 显示窗口
        setVisible(true);
    }
    
    /**
     * 设置UI默认值
     */
    private void setUIDefaults() {
        UIManager.put("Panel.background", Color.WHITE);
        UIManager.put("Label.foreground", Color.BLACK);
        UIManager.put("Button.background", Color.WHITE);
        UIManager.put("Button.foreground", Color.BLACK);
        UIManager.put("TextArea.background", Color.WHITE);
        UIManager.put("TextArea.foreground", Color.BLACK);
        UIManager.put("ScrollPane.background", Color.WHITE);
        UIManager.put("ScrollPane.foreground", Color.BLACK);
    }
    
    /**
     * 初始化MVC组件
     */
    private void initializeMVCComponents() {
        // 创建模型
        model = new GameModel();
        
        // 创建事件管理器
        eventManager = new EventManager();
        
        // 创建消息面板（在控制器之前创建，确保能接收到初始消息）
        messagePanel = new MessagePanel(new GameController(model, eventManager) {
            // 临时控制器，只用于获取事件管理器，覆盖initializeGame方法防止重复初始化
            @Override
            public EventManager getEventManager() {
                return eventManager;
            }
            
            // 覆盖initializeGame方法，防止重复初始化
            @Override
            protected void initializeGame() {
                // 不执行任何初始化操作
            }
        });
        
        // 创建控制器
        controller = new GameController(model, eventManager);
        
        // 创建场景管理器
        sceneManager = new SceneManager(controller);
        
        // 设置场景管理器到控制器
        controller.setSceneManager(sceneManager);
        
        // 监听游戏阶段变化
        eventManager.addGamePhaseChangeListener(this::onGamePhaseChanged);
        
        // 监听场景名称变化
        eventManager.addSceneNameChangeListener(this::onSceneNameChanged);
    }
    
    /**
     * 初始化UI组件
     */
    private void initializeUIComponents() {
        // 消息面板 (左侧 - 1/5宽度)
        JScrollPane messageScrollPane = new JScrollPane(messagePanel.getPanel());
        messageScrollPane.setPreferredSize(new Dimension(327, getHeight())); // 近似1/5宽度，现改为320
        messageScrollPane.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        add(messageScrollPane, BorderLayout.WEST);
        
        // 顶部按钮面板
        JPanel topButtonPanel = new JPanel();
        topButtonPanel.setBackground(Color.WHITE);
        topButtonPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
        add(topButtonPanel, BorderLayout.NORTH);
        
        JButton fireRoomButton = new JButton("生火间");
        currentScaleButton = new JButton("   /   ");
        longJourneyButton = new JButton("漫漫尘途"); // 使用类成员变量
        
        // 初始阶段只显示生火间按钮，其他按钮隐藏
        currentScaleButton.setVisible(false);
        longJourneyButton.setVisible(false);
        
        topButtonPanel.add(fireRoomButton);
        topButtonPanel.add(currentScaleButton);
        topButtonPanel.add(longJourneyButton);
        
        // 主内容面板 (中央)
        add(sceneManager.getMainContentPanel(), BorderLayout.CENTER);
        
        // 按钮动作切换场景
        fireRoomButton.addActionListener(e -> sceneManager.showScene(SceneManager.FIRE_ROOM_SCENE));
        currentScaleButton.addActionListener(e -> sceneManager.showScene(SceneManager.CURRENT_SCALE_SCENE));
        longJourneyButton.addActionListener(e -> sceneManager.showScene(SceneManager.LONG_JOURNEY_SCENE));
    }
    
    /**
     * 游戏阶段变化处理
     */
    private void onGamePhaseChanged(boolean isPhase2) {
        if (isPhase2) {
            // 更新当前规模按钮名称（初始为静谧森林，后续可能会变化）
            currentScaleButton.setText("静谧森林");
            
            // 在第二阶段显示所有按钮
            currentScaleButton.setVisible(true);
            longJourneyButton.setVisible(true);
        }
    }
    
    /**
     * 场景名称变化处理
     */
    private void onSceneNameChanged(String sceneName) {
          if ("孤独小屋".equals(sceneName)) {
              // 更新当前规模按钮名称
              currentScaleButton.setText("孤独小屋");
          }
      }
    
    /**
     * 主方法
     */
    public static void main(String[] args) {
        SwingUtilities.invokeLater(FireRoomGame::new);
    }
}