package src.exp3.Date;

import java.util.Calendar;
import java.util.Scanner;

public class Date{
    private final int year;
    private final int month;
    private final String monthName;

    // 补充：显式定义带三个参数的构造函数
    public Date(int year, int month, String monthName) {
        this.year = year;
        this.month = month;
        this.monthName = monthName;
        printMonthCalendar(); // 初始化时直接打印日历
    }
    private void printMonthCalendar() {
        Calendar cal = Calendar.getInstance();
        cal.set(year, month, 1); // 设置为该月第一天

        int dayOfWeek = cal.get(Calendar.DAY_OF_WEEK); // 第一天是星期几
        int daysInMonth = cal.getActualMaximum(Calendar.DAY_OF_MONTH); // 该月总天数
        // 打印月份标题
        System.out.printf("\n%20s %d\n", monthName, year);
        System.out.println(" Sun Mon Tue Wed Thu Fri Sat");
        // 首行缩进
        int leadingSpaces = (dayOfWeek == Calendar.SUNDAY) ? 0 : dayOfWeek - Calendar.SUNDAY;
        for (int i = 0; i < leadingSpaces; i++) {
            System.out.print("    ");
        }
        // 打印日期
        for (int day = 1; day <= daysInMonth; day++) {
            System.out.printf("%4d", day);
            if ((day + leadingSpaces) % 7 == 0) { // 每满7天换行
                System.out.println();
            }
        }
        // 如果最后一行未满，补一个换行
        if ((daysInMonth + leadingSpaces) % 7 != 0) {
            System.out.println();
        }
    }
}