package src.exp4;

@FunctionalInterface
interface Runnable {
    public abstract void run();
}

public class Demo1 {
    public static void main(String[] args) {
        Runnable r = () -> System.out.println("Hello from Runnable!");
        new Thread(r).start(); 
    }
}