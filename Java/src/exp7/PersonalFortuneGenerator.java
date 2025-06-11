package src.exp7;

import java.time.LocalDate;
import java.time.Period;
import java.util.Random;
import java.util.Scanner;

// 运势类型枚举
enum FortuneType {
    CAREER("事业"), WEALTH("财富"), HEALTH("健康"), LOVE("爱情");
    private String desc;
    FortuneType(String desc) {
        this.desc = desc;
    }
    public String getDesc() {
        return desc;
    }
}

// 幸运颜色枚举
enum LuckyColor {
    RED("RED"), GOLD("GOLD"), BLUE("BLUE"), GREEN("GREEN"), PURPLE("PURPLE");
    private String color;
    LuckyColor(String color) {
        this.color = color;
    }
    public String getColor() {
        return color;
    }
}

public class PersonalFortuneGenerator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // 获取用户输入
        System.out.print("请输入您的姓名：");
        String name = scanner.nextLine();
        System.out.print("请输入您的出生年份：");
        int year = scanner.nextInt();
        System.out.print("请输入您的出生月份：");
        int month = scanner.nextInt();
        System.out.print("请输入您的出生日期：");
        int day = scanner.nextInt();

        // 计算年龄
        LocalDate birthDate = LocalDate.of(year, month, day);
        LocalDate now = LocalDate.now();
        Period period = Period.between(birthDate, now);
        int age = period.getYears();

        System.out.println("\n--- 运势报告生成中... ---");
        // 随机选择运势类型和幸运颜色
        FortuneType[] fortuneTypes = FortuneType.values();
        FortuneType randomFortune = fortuneTypes[new Random().nextInt(fortuneTypes.length)];
        LuckyColor[] luckyColors = LuckyColor.values();
        LuckyColor randomColor = luckyColors[new Random().nextInt(luckyColors.length)];

        // 生成幸运数字
        int nameLength = name.length();
        int luckyNumber = new Random().nextInt(100) + 1; // 生成 1 - 100 的随机数
        // 这里简单模拟题目示例中的计算逻辑（姓名长度 * 有关的数，示例里张三长度 2，2*38.5 约 77，这里简化用随机数，也可按需求调整）
        // 若严格按题目示例逻辑，可改成：int luckyNumber = nameLength * 38 + 1; 等，保证结果接近示例
        // 这里为演示随机逻辑，保留随机生成，实际可根据需求调整计算方式

        // 生成运势报告
        String fortuneReport = String.format("尊敬的 %s（%d岁），这是您今天的专属运势：\n\n" +
                        "今日主题：%s（%s）\n" +
                        "幸运颜色：%s\n" +
                        "幸运数字：%d\n" +
                        "今日箴言：今天适合多进行户外活动，呼吸新鲜空气，身体是革命的本钱！\n\n" +
                        "祝您今天好运！",
                name, age, randomFortune, randomFortune.getDesc(), randomColor.getColor(), luckyNumber);
        System.out.println(fortuneReport);

        scanner.close();
    }
}