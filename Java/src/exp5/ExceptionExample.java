package src.exp5;

public class ExceptionExample {
    public static void main(String[] args) {
        try {
            // 抛出一个带有字符串参数的 Exception 对象
            throw new Exception("这是一个自定义异常消息");
        } catch (Exception e) {
            // 捕获异常并打印异常消息
            System.out.println("捕获到异常: " + e.getMessage());
        } finally {
            // 无论是否发生异常，都会执行此块
            System.out.println("这是 finally 块中的消息");
        }
    }
}