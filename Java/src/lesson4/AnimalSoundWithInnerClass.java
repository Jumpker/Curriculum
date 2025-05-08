package src.lesson4;

// 定义动物接口
interface Animal {
    void makeSound(); // 发出叫声的方法
}
abstract class AnimalSound {
    AnimalSound(String name) {
    }
    abstract void makeSound();
}
// 直接使用匿名内部类
public class AnimalSoundWithInnerClass {

    public static void main(String[] args) {
        Animal dog = new Animal() {
            @Override
            public void makeSound() {
                System.out.println("汪汪汪！ (来自匿名内部类Dog)");
            }
        };
        dog.makeSound();

        AnimalSound cat = new AnimalSound("Cat") {
            @Override
            public void makeSound() {
                System.out.println("喵喵喵！ (来自匿名内部类Cat)");
            }
        };
        cat.makeSound();
    }
}
