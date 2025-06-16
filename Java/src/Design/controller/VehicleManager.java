package src.Design.controller;

import src.Design.model.GameModel;
import src.Design.event.EventManager;

/**
 * 车辆管理器类，负责处理车辆相关的逻辑
 */
public class VehicleManager {
    private GameModel model;
    private EventManager eventManager;
    private static final int DEFAULT_WOOD_GAIN = 10;
    private static final int CART_WOOD_GAIN = 50;
    
    /**
     * 构造函数
     * @param model 游戏模型
     * @param eventManager 事件管理器
     */
    public VehicleManager(GameModel model, EventManager eventManager) {
        this.model = model;
        this.eventManager = eventManager;
    }
    
    /**
     * 建造货车
     * @return 是否成功建造
     */
    public boolean buildCart() {
        if (hasCart() || model.getResource("木头") < 30) {
            return false;
        }
        
        model.decreaseResource("木头", 30);
        model.increaseBuilding("货车");
        
        // 通知资源变化
        eventManager.notifyResourceChangeListeners(model.getResources());
        
        return true;
    }
    
    /**
     * 获取伐木获得的木头数量
     * @return 木头数量
     */
    public int getWoodGainAmount() {
        return hasCart() ? CART_WOOD_GAIN : DEFAULT_WOOD_GAIN;
    }
    
    /**
     * 是否已有货车
     * @return 是否已有货车
     */
    public boolean hasCart() {
        return model.getBuilding("货车") > 0;
    }
    
    /**
     * 获取货车数量
     * @return 货车数量
     */
    public int getCartCount() {
        return model.getBuilding("货车");
    }
}