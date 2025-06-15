package src.Design.model;

import java.util.HashMap;
import java.util.Map;

/**
 * 游戏模型类，负责管理游戏状态和数据
 */
public class GameModel {
    private Map<String, Integer> resources = new HashMap<>();
    private Map<String, Integer> buildings = new HashMap<>();
    private int roomHeat = 2; // 初始房间温度，0-5级
    private boolean gamePhase2 = false; // 游戏第二阶段标志
    private String[] roomStatusMessages = {"房间冰冷刺骨.", "房间很冷.", "房间暖和.", "房间很宜人.", "房间很暖.", "房间很热."};
    
    /**
     * 构造函数
     */
    public GameModel() {
        // 初始化资源和建筑
        initializeResources();
        initializeBuildings();
    }
    
    /**
     * 初始化资源
     */
    private void initializeResources() {
        // 初始没有资源
    }
    
    /**
     * 初始化建筑
     */
    private void initializeBuildings() {
        // 初始没有建筑
    }
    
    /**
     * 获取资源
     * @param resourceName 资源名称
     * @return 资源数量
     */
    public int getResource(String resourceName) {
        return resources.getOrDefault(resourceName, 0);
    }
    
    /**
     * 获取所有资源
     * @return 资源映射
     */
    public Map<String, Integer> getResources() {
        return resources;
    }
    
    /**
     * 增加资源
     * @param resourceName 资源名称
     * @param amount 增加数量
     */
    public void increaseResource(String resourceName, int amount) {
        resources.put(resourceName, getResource(resourceName) + amount);
    }
    
    /**
     * 减少资源
     * @param resourceName 资源名称
     * @param amount 减少数量
     * @return 是否成功减少
     */
    public boolean decreaseResource(String resourceName, int amount) {
        int currentAmount = getResource(resourceName);
        if (currentAmount >= amount) {
            resources.put(resourceName, currentAmount - amount);
            return true;
        }
        return false;
    }
    
    /**
     * 获取建筑数量
     * @param buildingName 建筑名称
     * @return 建筑数量
     */
    public int getBuilding(String buildingName) {
        return buildings.getOrDefault(buildingName, 0);
    }
    
    /**
     * 获取所有建筑
     * @return 建筑映射
     */
    public Map<String, Integer> getBuildings() {
        return buildings;
    }
    
    /**
     * 增加建筑
     * @param buildingName 建筑名称
     */
    public void increaseBuilding(String buildingName) {
        buildings.put(buildingName, getBuilding(buildingName) + 1);
    }
    
    /**
     * 获取房间温度
     * @return 房间温度
     */
    public int getRoomHeat() {
        return roomHeat;
    }
    
    /**
     * 增加房间温度
     */
    public void increaseRoomHeat() {
        roomHeat = Math.min(roomStatusMessages.length - 1, roomHeat + 1);
    }
    
    /**
     * 减少房间温度
     */
    public void decreaseRoomHeat() {
        roomHeat = Math.max(0, roomHeat - 1);
    }
    
    /**
     * 获取房间状态消息
     * @return 房间状态消息
     */
    public String getRoomStatusMessage() {
        return roomStatusMessages[Math.min(roomHeat, roomStatusMessages.length - 1)];
    }
    
    /**
     * 是否为游戏第二阶段
     * @return 是否为游戏第二阶段
     */
    public boolean isGamePhase2() {
        return gamePhase2;
    }
    
    /**
     * 设置游戏第二阶段
     * @param gamePhase2 是否为游戏第二阶段
     */
    public void setGamePhase2(boolean gamePhase2) {
        this.gamePhase2 = gamePhase2;
    }
}