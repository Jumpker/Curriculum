package src.exp5;

import java.util.InputMismatchException;
import java.util.Scanner;

public class DivisionCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("请输入第一个数: ");
            double num1 = scanner.nextDouble();
            System.out.print("请输入第二个数: ");
            double num2 = scanner.nextDouble();

            // 执行除法运算
            double result = divide(num1, num2);
            System.out.println("结果: " + result);
        } catch (InputMismatchException e) {
            System.out.println("输入错误，请输入有效的数字。");
        } catch (ArithmeticException e) {
            System.out.println("错误: 除数不能为零。");
        } finally {
            scanner.close();
        }
    }

    public static double divide(double dividend, double divisor) {
        if (divisor == 0) {
            throw new ArithmeticException();
        }
        return dividend / divisor;
    }
}