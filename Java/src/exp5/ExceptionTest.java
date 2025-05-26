package src.exp5;

// 自定义异常类，继承自 Exception 类
class MyException extends Exception {
    private String errorMessage;

    // 构造方法，接收一个 String 类型的参数
    public MyException(String message) {
        this.errorMessage = message;
    }
    // 打印保存的 String 对象的方法
    public void printErrorMessage() {
        System.out.println(errorMessage);
    }
}

// 主类，包含 main() 方法
public class ExceptionTest {
    public static void main(String[] args) {
        try {
            // 创建并抛出 MyException 类的对象
            throw new MyException("这是自定义异常传递的消息");
        } catch (MyException e) {
            // 捕获异常并打印传递的 String 消息
            System.out.print("捕获到自定义异常，消息为: ");
            e.printErrorMessage();
        }
    }
}