package src.exp2.Student;

public class Student {
    private int id;
    private String name;
    private boolean sex;
    private int age;
    private int class_id;

    Student(int id, String name, boolean sex, int age, int class_id){
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.age = age;
        this.class_id = class_id;
    }

    public int GetClass_id(){                       //获得班号
        return this.class_id;
    }

    public String GetName(){                        //获得学生姓名
        return this.name;
    }

    public int GetAge(){                            //获得学生年龄
        return this.age;
    }

    public void SetAge(int age) {                   //修改学生年龄
        this.age = age;
    }

    public String toString(){                       //返回学生信息
        return "学号：" + this.id +
                " \n姓名：" + this.name +
                " \n性别：" + (this.sex ? "男" : "女") +
                " \n年龄：" + this.age +
                " \n班号：" + this.class_id;
    }
}
