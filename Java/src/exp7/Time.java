package src.exp7;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Period;
import java.time.Duration;
import java.time.format.DateTimeFormatter;
import java.time.DayOfWeek;

public class Time {
    public static void main(String[] args) {
        // 获取当前本地日期，使用 LocalDate.now() 方法
        LocalDate dateOne = LocalDate.now();
        // 定义一个自定义日期，例如2025年1月22日，使用 LocalDate.of() 方法
        LocalDate dateTwo = LocalDate.of(2025, 1, 22);

        // 打印本地日期和自定义日期，并使用 DateTimeFormatter.ofPattern() 格式化输出
        System.out.println("本地日期:" + dateOne.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
        System.out.println("自定日期:" + dateTwo.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));

        // 判断两个日期的前后关系和是否相等，使用 isAfter()、isBefore()、isEqual() 方法
        System.out.println(dateOne.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + "在" + dateTwo.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + "之后:" + dateOne.isAfter(dateTwo));
        System.out.println(dateOne.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + "在" + dateTwo.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + "之前:" + dateOne.isBefore(dateTwo));
        System.out.println(dateOne.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + "和" + dateTwo.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + "相同:" + dateOne.isEqual(dateTwo));

        // 计算dateOne日期18年前的日期，使用 minusYears() 方法
        LocalDate dateOne18YearsAgo = dateOne.minusYears(18);
        System.out.println(dateOne.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + " 18年前是:");
        System.out.println(dateOne18YearsAgo.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
        // 获取该日期是星期几，使用 getDayOfWeek() 方法
        System.out.println("那天是" + dateOne18YearsAgo.getDayOfWeek());

        // 计算dateTwo日期18年零23个月、8976天之后的日期
        // 使用 Period.of() 创建周期，plus() 增加周期，plusDays() 增加天数
        LocalDate dateTwoAfterPeriod = dateTwo.plus(Period.of(18, 23, 0)).plusDays(8976);
        System.out.println(dateTwo.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")) + "再过18年23个月8976天之后是:");
        System.out.println(dateTwoAfterPeriod.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
        // 获取该日期是星期几，使用 getDayOfWeek() 方法
        System.out.println("那天是" + dateTwoAfterPeriod.getDayOfWeek());

        // 计算当前日期下23:30:01再过1897秒后的时间
        // 使用 LocalDateTime.of() 创建日期时间，Duration.ofSeconds() 创建持续时间，plus() 增加持续时间
        LocalDateTime time = LocalDateTime.of(LocalDate.now(), java.time.LocalTime.of(23, 30, 1));
        LocalDateTime timeAfterSeconds = time.plus(Duration.ofSeconds(1897));
        System.out.println("23:30:01再过1897秒是:" + timeAfterSeconds.format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }
}