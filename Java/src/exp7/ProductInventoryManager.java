package src.exp7;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ProductInventoryManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("欢迎使用产品库存管理系统！");
        System.out.println("请选择要创建的产品类别：");
        System.out.println("1. 食品 (FOOD)");
        System.out.println("2. 电子产品 (ELECTRONICS)");
        System.out.println("3. 服装 (CLOTHING)");
        System.out.print("请输入您的选择 (1-3): ");

        int choice = -1;
        try {
            choice = scanner.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("无效输入，请输入一个数字。");
            scanner.next(); // 无效的输入
        }

        ProductCategory selectedCategory = null;
        switch (choice) {
            case 1:
                selectedCategory = ProductCategory.FOOD;
                break;
            case 2:
                selectedCategory = ProductCategory.ELECTRONICS;
                break;
            case 3:
                selectedCategory = ProductCategory.CLOTHING;
                break;
            default:
                System.out.println("无效的选择，程序将退出。");
                break;
        }

        if (selectedCategory != null) {
            Product product = new Product(selectedCategory);
            System.out.println("\n产品信息已生成：");
            System.out.println(product);
        }

        scanner.close();
    }
}