package src.exp3;

class Student{
    String name;
    char gender;
    int age;
    String[] courseNames;
    double[] courseScores;
    public Student (){                                      //构造方法
        name = "什么厂财学生，没听说过";
        gender = '男';
        age = 0;
        courseNames = new String[3];
        courseScores = new double[3];
        courseNames[0] = "计算机";
        courseNames[1] = "数学";
        courseNames[2] = "英语";
        courseScores[0] = courseScores[1] = courseScores[2] = 0;
    }
    public Student (String n, char s, int a){               //带参构造方法
        name = n;
        gender = s;
        age = a;
        courseNames = new String[3];
        courseScores = new double[3];
        courseNames[0] = "计算机";
        courseNames[1] = "数学";
        courseNames[2] = "英语";
        courseScores[0] = courseScores[1] = courseScores[2] = 0;
    }
    public void introduceMe(){                              //成员方法
        System.out.println("我的名字是：" + name);
        System.out.println("我的性别和年龄分别是：" + gender + "、" + age);
        System.out.println("我的成绩还没有录入！");
    }
}


public class TestStudent {
    public static void main(String[] args) {
        Student stu1 = new Student();
        Student stu2 = new Student("张山", 'M', 23);

        stu1.introduceMe();
        System.out.println();
        stu2.introduceMe();
    }
}
