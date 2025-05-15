package src.lesson5;
import java.util.Scanner;

class LoginException extends Exception {
    LoginException(String message) {
        super(message); // 正确调用 java.lang.Exception 的构造方法
    }
}

class checkLogin {
    static String user = "admin";
    static String password = "123456"; 
    // 修改参数名避免与类静态变量冲突
    static void checkLogin(String login, String inputPassword) throws LoginException {
        try {
            // 修正密码验证逻辑：比较输入密码与存储的密码
            if (!login.equals(user) || !inputPassword.equals(password)) {
                throw new LoginException("Login incorrect");
            }
        } catch (LoginException e) {
            System.out.println(e.getMessage());
        }
    }
}

// 主类名修改为 LoginDemo（避免与 java.lang.Exception 冲突）
public class LoginDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();
        try {
            // 使用用户输入的变量进行验证
            checkLogin.checkLogin(username, password);
        } catch (LoginException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Login successful");
    }
}
