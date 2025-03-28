package src.exp2.Student;

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student(1, "张三", true, 20, 1);
        System.out.println(s1.GetAge());        //修改前
        s1.SetAge(18);
        System.out.println(s1.GetAge());        //修改后
        System.out.println(s1.toString());      //输出学生信息
    }
}
