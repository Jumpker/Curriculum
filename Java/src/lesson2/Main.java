package src.lesson2;

class Person {
    String name;

    Person(String name) {
        this.name = name;
    }

    public void eat() {
        System.out.println("人类在吃饭");
    }

     class Student extends Person{
        Student (String name){
            super(name);
        }
        @Override
         public void eat() {
             System.out.println(name + "学生在吃饭");
         }
     }
}

public class Main {
    public static void main(String[] args) {
        Person person = new Person("张三");
        person.eat();
        Person.Student student = person.new Student("李四");
        student.eat();
    }
}
