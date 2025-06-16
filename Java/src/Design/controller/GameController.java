package src.Design.controller;

import src.Design.event.EventManager;
import src.Design.model.GameModel;
import src.Design.view.SceneManager;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Map;

/**
 * 游戏控制器类，负责处理游戏逻辑
 */
public class GameController {
    private GameModel model;
    private EventManager eventManager;
    private SceneManager sceneManager;
    private TrapManager trapManager;
    private VehicleManager vehicleManager;
    
    /**
     * 构造函数
     * @param model 游戏模型
     * @param eventManager 事件管理器
     */
    public GameController(GameModel model, EventManager eventManager) {
        this.model = model;
        this.eventManager = eventManager;
        this.trapManager = new TrapManager(model, eventManager);
        this.vehicleManager = new VehicleManager(model, eventManager);
        
        // 初始化游戏
        initializeGame();
    }
    
    /**
     * 初始化游戏
     */
    protected void initializeGame() {
        // 添加初始木头资源（不显示）
        model.increaseResource("木头", 10);
        
        // 使用计时器延迟添加初始消息，确保消息监听器已经注册
        Timer initialMessageTimer = new Timer(500, e -> {
            // 添加初始消息
            addMessage("火堆熄灭了.");
            addMessage("房间冰冷刺骨.");
        });
        initialMessageTimer.setRepeats(false);
        initialMessageTimer.start();
        
        // 启动房间状态更新计时器
        startRoomStatusTimer();
    }
    
    /**
     * 启动房间状态更新计时器
     */
    private void startRoomStatusTimer() {
        Timer roomStatusTimer = new Timer(10000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                model.decreaseRoomHeat();
                addMessage(model.getRoomStatusMessage());
            }
        });
        roomStatusTimer.setRepeats(true);
        roomStatusTimer.start();
    }
    
    /**
     * 添加燃料（添柴）
     */
    public void addFuel() {
        if (model.isGamePhase2()) {
            // 第二阶段：需要消耗木头
            int currentWood = model.getResource("木头");
            if (currentWood >= 1) {
                model.decreaseResource("木头", 1);
                model.increaseRoomHeat();
                String[] messages = {"火堆冒出火苗.", "火光映出窗外，射入黑暗之中.", "火堆燃烧着.", "火堆熊熊燃烧."};
                addMessage(messages[(int) (Math.random() * messages.length)]);
                eventManager.notifyResourceChangeListeners(model.getResources());
            } else {
                addMessage("木头不够了.");
            }
        } else {
            // 第一阶段：不需要消耗木头，可以无限添柴
            model.increaseRoomHeat();
            String[] messages = {"火堆冒出火苗.", "火光映出窗外，射入黑暗之中.", "火堆燃烧着.", "火堆熊熊燃烧."};
            addMessage(messages[(int) (Math.random() * messages.length)]);
            
            // 游戏进程基于第一次点击
            if (!model.isGamePhase2()) {
                triggerGameProgression();
            }
        }
    }
    
    /**
     * 触发游戏进程
     */
    private void triggerGameProgression() {
        model.setGamePhase2(true);
        Timer strangerArrivalTimer = new Timer(10000, ev -> {
            addMessage("一个衣衫褴褛的陌生人步履蹒跚地步入门来，瘫倒在角落里.");
            Timer strangerMumbleTimer = new Timer(10000, ev2 -> {
                addMessage("陌生人瑟瑟发抖，呢喃不已，听不清在说些什么.");
                Timer strangerCalmTimer = new Timer(10000, ev3 -> {
                    addMessage("角落里的陌生人不再颤抖了，她的呼吸平静了下来.");
                    Timer strangerHelpTimer = new Timer(5000, ev4 -> {
                        addMessage("那名陌生人站在火堆旁.她说她可以帮忙。她说她会建东西.");
                        // 触发游戏第二阶段
                        triggerGamePhase2();
                    });
                    strangerHelpTimer.setRepeats(false);
                    strangerHelpTimer.start();
                });
                strangerCalmTimer.setRepeats(false);
                strangerCalmTimer.start();
            });
            strangerMumbleTimer.setRepeats(false);
            strangerMumbleTimer.start();
        });
        strangerArrivalTimer.setRepeats(false);
        strangerArrivalTimer.start();
    }
    
    /**
     * 触发游戏第二阶段
     */
    private void triggerGamePhase2() {
        // 重置木头资源为5
        model.getResources().clear();
        model.increaseResource("木头", 5);
        eventManager.notifyResourceChangeListeners(model.getResources());
        
        // 通知游戏阶段变化
        eventManager.notifyGamePhaseChangeListeners(true);
        
        // 第二阶段消息
        Timer phase2MessagesTimer = new Timer(15000, e -> {
            addMessage("建造者说他能够制作陷阱来捕捉那些仍在野外活动的野兽.");
            Timer message2Timer = new Timer(5000, ev2 -> {
                addMessage("建造者说他能够制造出货车，用来运载木头.");
                Timer message3Timer = new Timer(5000, ev3 -> {
                    addMessage("建造者说这里有许多流浪者，他们也会来工作.");
                });
                message3Timer.setRepeats(false);
                message3Timer.start();
            });
            message2Timer.setRepeats(false);
            message2Timer.start();
        });
        phase2MessagesTimer.setRepeats(false);
        phase2MessagesTimer.start();
    }
    
    /**
     * 伐木
     */
    public void chopWood() {
        int woodAmount = vehicleManager.getWoodGainAmount();
        model.increaseResource("木头", woodAmount);
        eventManager.notifyResourceChangeListeners(model.getResources());
        addMessage("林地上散落着枯枝败叶.");
    }
    
    /**
     * 建造小屋
     */
    public void buildHut() {
        if (model.getResource("木头") >= 100) {
            model.decreaseResource("木头", 100);
            model.increaseBuilding("小屋");
            eventManager.notifyResourceChangeListeners(model.getResources());
            addMessage("建造者在林中建起一栋小屋，他说消息很快就会流传出去.");
        } else {
            addMessage("木头不够了.");
        }
    }
    
    /**
     * 建造陷阱
     */
    public void buildTrap() {
        if (model.getResource("木头") >= 10) {
            model.decreaseResource("木头", 10);
            model.increaseBuilding("陷阱");
            eventManager.notifyResourceChangeListeners(model.getResources());
            addMessage("陷阱越多，抓到的猎物就越多.");
        } else {
            addMessage("木头不够了.");
        }
    }
    
    /**
     * 建造货车
     */
    public void buildCart() {
        if (vehicleManager.hasCart()) {
            addMessage("已经有一辆货车了，不需要再建造.");
            return;
        }
        
        if (model.getResource("木头") >= 30) {
            if (vehicleManager.buildCart()) {
                addMessage("货车可以帮助运载更多的木头.");
                addMessage("摇摇晃晃的货车满载从森林运出木头.");
                
                // 通知建筑面板更新（移除货车按钮）
                eventManager.notifyBuildingChangeListeners(model.getBuildings());
            }
        } else {
            addMessage("木头不够了.");
        }
    }
    
    /**
     * 添加消息
     * @param message 消息内容
     */
    public void addMessage(String message) {
        eventManager.notifyMessageListeners(message);
    }
    
    /**
     * 获取游戏模型
     * @return 游戏模型
     */
    public GameModel getModel() {
        return model;
    }
    
    /**
     * 获取陷阱管理器
     * @return 陷阱管理器
     */
    public TrapManager getTrapManager() {
        return trapManager;
    }
    
    /**
     * 检查陷阱
     */
    public void checkTraps() {
        trapManager.checkTraps();
    }
    
    /**
     * 获取事件管理器
     * @return 事件管理器
     */
    public EventManager getEventManager() {
        return eventManager;
    }
    
    /**
     * 设置场景管理器
     * @param sceneManager 场景管理器
     */
    public void setSceneManager(SceneManager sceneManager) {
        this.sceneManager = sceneManager;
    }
    
    /**
     * 获取场景管理器
     * @return 场景管理器
     */
    public SceneManager getSceneManager() {
        return sceneManager;
    }
}