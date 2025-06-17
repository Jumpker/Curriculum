package src.Design.event;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.function.Consumer;

/**
 * 事件管理器类，负责处理游戏中的各种事件
 */
public class EventManager {
    // 消息监听器列表
    private List<Consumer<String>> messageListeners = new ArrayList<>();
    
    // 资源变化监听器列表
    private List<Consumer<Map<String, Integer>>> resourceChangeListeners = new ArrayList<>();
    
    // 游戏阶段变化监听器列表
    private List<Consumer<Boolean>> gamePhaseChangeListeners = new ArrayList<>();
    
    /**
     * 添加消息监听器
     */
    public void addMessageListener(Consumer<String> listener) {
        messageListeners.add(listener);
    }
    
    /**
     * 移除消息监听器
     */
    public void removeMessageListener(Consumer<String> listener) {
        messageListeners.remove(listener);
    }
    
    /**
     * 发送消息给所有监听器
     */
    public void fireMessage(String message) {
        for (Consumer<String> listener : messageListeners) {
            listener.accept(message);
        }
    }
    
    /**
     * 通知所有消息监听器（别名方法，与fireMessage功能相同）
     */
    public void notifyMessageListeners(String message) {
        fireMessage(message);
    }
    
    /**
     * 添加资源变化监听器
     */
    public void addResourceChangeListener(Consumer<Map<String, Integer>> listener) {
        resourceChangeListeners.add(listener);
    }
    
    /**
     * 移除资源变化监听器
     */
    public void removeResourceChangeListener(Consumer<Map<String, Integer>> listener) {
        resourceChangeListeners.remove(listener);
    }
    
    /**
     * 通知所有资源变化监听器
     */
    public void fireResourceChanged(Map<String, Integer> resources) {
        for (Consumer<Map<String, Integer>> listener : resourceChangeListeners) {
            listener.accept(resources);
        }
    }
    
    /**
     * 通知所有资源变化监听器（别名方法，与fireResourceChanged功能相同）
     */
    public void notifyResourceChangeListeners(Map<String, Integer> resources) {
        fireResourceChanged(resources);
    }
    
    /**
     * 添加游戏阶段变化监听器
     */
    public void addGamePhaseChangeListener(Consumer<Boolean> listener) {
        gamePhaseChangeListeners.add(listener);
    }
    
    /**
     * 移除游戏阶段变化监听器
     */
    public void removeGamePhaseChangeListener(Consumer<Boolean> listener) {
        gamePhaseChangeListeners.remove(listener);
    }
    
    /**
     * 通知所有游戏阶段变化监听器
     */
    public void fireGamePhaseChanged(boolean isPhase2) {
        for (Consumer<Boolean> listener : gamePhaseChangeListeners) {
            listener.accept(isPhase2);
        }
    }
    
    /**
     * 通知所有游戏阶段变化监听器（别名方法，与fireGamePhaseChanged功能相同）
     */
    public void notifyGamePhaseChangeListeners(boolean isPhase2) {
        fireGamePhaseChanged(isPhase2);
    }
    
    // 建筑变化监听器列表
    private List<Consumer<Map<String, Integer>>> buildingChangeListeners = new ArrayList<>();
    
    /**
     * 添加建筑变化监听器
     */
    public void addBuildingChangeListener(Consumer<Map<String, Integer>> listener) {
        buildingChangeListeners.add(listener);
    }
    
    /**
     * 移除建筑变化监听器
     */
    public void removeBuildingChangeListener(Consumer<Map<String, Integer>> listener) {
        buildingChangeListeners.remove(listener);
    }
    
    /**
     * 通知所有建筑变化监听器
     */
    public void fireBuildingChanged(Map<String, Integer> buildings) {
        for (Consumer<Map<String, Integer>> listener : buildingChangeListeners) {
            listener.accept(buildings);
        }
    }
    
    /**
     * 通知所有建筑变化监听器（别名方法，与fireBuildingChanged功能相同）
     */
    public void notifyBuildingChangeListeners(Map<String, Integer> buildings) {
        fireBuildingChanged(buildings);
    }
    
    // 场景名称变化监听器列表
    private List<Consumer<String>> sceneNameChangeListeners = new ArrayList<>();
    
    /**
     * 添加场景名称变化监听器
     */
    public void addSceneNameChangeListener(Consumer<String> listener) {
        sceneNameChangeListeners.add(listener);
    }
    
    /**
     * 移除场景名称变化监听器
     */
    public void removeSceneNameChangeListener(Consumer<String> listener) {
        sceneNameChangeListeners.remove(listener);
    }
    
    /**
     * 通知所有场景名称变化监听器
     */
    public void fireSceneNameChanged(String sceneName) {
        for (Consumer<String> listener : sceneNameChangeListeners) {
            listener.accept(sceneName);
        }
    }
    
    /**
     * 通知所有场景名称变化监听器（别名方法，与fireSceneNameChanged功能相同）
     */
    public void notifySceneNameChangeListeners(String sceneName) {
        fireSceneNameChanged(sceneName);
    }
}