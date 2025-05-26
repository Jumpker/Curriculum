package src.exp5;

import java.util.InputMismatchException;
import java.util.Scanner;

class NegativeRadiusException extends Exception {
    public NegativeRadiusException(String message) {
        super(message);
    }
}

public class CircleAreaCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double radius = 0;
        boolean validInput = false;

        while (!validInput) {
            try {
                System.out.print("请输入圆的半径: ");
                radius = scanner.nextDouble();
                // 检查半径是否为负数，如果是则抛出自定义异常
                if (radius < 0) {
                    throw new NegativeRadiusException("错误：圆的半径不能为负数，请输入有效的正数。");
                }
                validInput = true;
            } catch (InputMismatchException e) {
                System.out.println("输入错误，请输入有效的数字。");
                scanner.nextLine(); // 清除无效输入
            } catch (NegativeRadiusException e) {
                System.out.println(e.getMessage());
            }
        }

        // 计算圆的面积
        double area = Math.PI * radius * radius;
        System.out.println("圆的面积是: " + area);

        // 关闭 Scanner 对象，释放资源
        scanner.close();
    }
}