package src.exp3;

class Person{
    private String name;
    private String address;
    private int phoneNumber;
    private String emailAddress;
    public Person(){
        this.name = "暂未定义姓名";
        this.address = "暂未定义地址";
        this.phoneNumber = 10086;
        this.emailAddress = "暂未定义邮箱地址";
    }
    public String ToString(){
        return "姓名：" + this.name + "\n地址：" + this.address + "\n电话：" + this.phoneNumber + "\n邮箱：" + this.emailAddress + "\n";
    }
}

class Student extends Person{
    private String grade;
    public Student(){
        this.grade = "暂未定义年级";
    }
}

class Employee extends Person{
    private String office;
    private double salary;
    private String date;
    public Employee(){
        this.office = "暂未定义办公地点";
        this.salary = 0;
        this.date = "暂未定义入职日期";
    }
}

class MyDate{
    private int year;
    private int month;
    private int day;
    public MyDate(){
        this.year = 2025;
        this.month = 1;
        this.day = 1;
    }
}

class Faculty extends Person{
    private MyDate date;
    private String level;
    public Faculty(){
        this.date = new MyDate();
        this.level = "暂未定义级别";
    }
}

class Staff extends Person{
    private String title;
    public Staff(){
        this.title = "暂未定义职称";
    }
}

public class School {
    public static void main(String[] args) {
        Person person = new Person();
        System.out.println(person.ToString());
        Person student = new Student();
        System.out.println(student.ToString());
        Person employee = new Employee();
        System.out.println(employee.ToString());
        Person faculty = new Faculty();
        System.out.println(faculty.ToString());
        Person staff = new Staff();
        System.out.println(staff.ToString());
    }
}
