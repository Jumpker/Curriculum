package src.exp2.Date;

public class Date {
    private int year;
    private int month;
    private int day;

    Date(){                         //构造函数, 日期默认值
        this.year = 2008;
        this.month = 1;
        this.day = 1;
    }

    Date(int year, int month, int day){     //构造函数, 自定义日期值
        this.year = year;
        this.month = month;
        this.day = day;
    }

    int getYear(){                          //成员方法, 获取年份
        return year;
    }

    int getMonth(){                         //成员方法, 获取月份
        return month;
    }

    int getDay(){                           //成员方法, 获取日期
        return day;
    }

    void showDay(){                         //按“yyyy年mm月dd日”格式显示一个日期
        System.out.println(year + "年" + month + "月" + day + "日");
    }
}
