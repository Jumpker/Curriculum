package src.exp2.exp2_5.Date;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入年份（例如 2023）: ");
        int year = scanner.nextInt();
        scanner.close();

        String[] months = {
                "一月", "二月", "三月", "四月", "五月", "六月",
                "七月", "八月", "九月", "十月", "十一月", "十二月"
        };

        for (int month = 0; month < 12; month++) {
            new Date(year, month, months[month]);
        }
    }
}