package src.Design.controller;

import src.Design.model.GameModel;
import src.Design.event.EventManager;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * 陷阱管理器类，负责处理陷阱相关的逻辑
 */
public class TrapManager {
    private GameModel model;
    private EventManager eventManager;
    private Random random;
    
    /**
     * 构造函数
     * @param model 游戏模型
     * @param eventManager 事件管理器
     */
    public TrapManager(GameModel model, EventManager eventManager) {
        this.model = model;
        this.eventManager = eventManager;
        this.random = new Random();
    }
    
    /**
     * 检查陷阱
     * 随机获得0~n个毛皮、肉和牙齿（n为陷阱数量）
     */
    public void checkTraps() {
        int trapCount = model.getBuilding("陷阱");
        if (trapCount <= 0) {
            return;
        }
        
        // 随机获得资源
        int furCount = random.nextInt(trapCount + 1); // 0到trapCount
        int meatCount = random.nextInt(trapCount + 1);
        int toothCount = random.nextInt(trapCount + 1);
        
        // 添加资源到模型
        if (furCount > 0) {
            model.increaseResource("毛皮", furCount);
        }
        if (meatCount > 0) {
            model.increaseResource("肉", meatCount);
        }
        if (toothCount > 0) {
            model.increaseResource("牙齿", toothCount);
        }
        
        // 生成消息
        String message = generateTrapMessage(furCount, meatCount, toothCount);
        if (!message.isEmpty()) {
            addMessage(message);
        }
        
        // 通知资源变化
        eventManager.notifyResourceChangeListeners(model.getResources());
    }
    
    /**
     * 生成陷阱捕获消息
     * @param furCount 毛皮数量
     * @param meatCount 肉数量
     * @param toothCount 牙齿数量
     * @return 消息字符串
     */
    private String generateTrapMessage(int furCount, int meatCount, int toothCount) {
        List<String> items = new ArrayList<>();
        
        if (furCount > 0) {
            items.add("毛皮碎片");
        }
        if (meatCount > 0) {
            items.add("小片肉");
        }
        if (toothCount > 0) {
            items.add("残缺牙齿");
        }
        
        if (items.isEmpty()) {
            return "陷阱一无所获    .";
        }
        
        StringBuilder messageBuilder = new StringBuilder("陷阱捕获到");
        for (int i = 0; i < items.size(); i++) {
            if (i > 0 && i == items.size() - 1) {
                messageBuilder.append("和");
            } else if (i > 0) {
                messageBuilder.append("和");
            }
            messageBuilder.append(items.get(i));
        }
        messageBuilder.append(".");
        
        return messageBuilder.toString();
    }
    
    /**
     * 添加消息
     * @param message 消息内容
     */
    private void addMessage(String message) {
        eventManager.notifyMessageListeners(message);
    }
    
    /**
     * 获取陷阱数量
     * @return 陷阱数量
     */
    public int getTrapCount() {
        return model.getBuilding("陷阱");
    }
}