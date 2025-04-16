package src.exp2.exp2_5.Course;

public class Course {
    private int cNnumber;
    private String cName;
    private int cuit;
    //构造方法===============================================
    public Course(int cNnumber, String cName, int cuit) {
        this.cNnumber = cNnumber;
        this.cName = cName;
        this.cuit = cuit;
    }
    //输出课程信息
    public void printCourseInfo(){
        System.out.println("\n课程号：" + cNnumber +
                            "\n课程名：" + cName +
                            "\n学分数：" + cuit);
    }
}
