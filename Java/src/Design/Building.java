package src.Design;

import java.util.Map;

public interface Building {
    String getName();
    String getCostDisplay();
    int getCost();
    int getMaxCount();
    void build(Map<String, Integer> resources, Runnable updateResourceDisplay, Runnable addMessage);
    int getCurrentCount();
    void incrementCount();
}