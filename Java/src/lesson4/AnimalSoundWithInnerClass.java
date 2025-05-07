package src.lesson4;

// 定义动物接口
interface Animal {
    void makeSound(); // 发出叫声的方法
}

// 主类，用于演示
public class AnimalSoundWithInnerClass {

    public static void main(String[] args) {
        Animal dog = new Animal() {
            @Override
            public void makeSound() {
                System.out.println("汪汪汪！ (来自匿名内部类Dog)");
            }
        };
        dog.makeSound();

        Animal cat = new Animal() {
            @Override
            public void makeSound() {
                System.out.println("喵喵喵！ (来自匿名内部类Cat)");
            }
        };
        cat.makeSound();
    }
}
