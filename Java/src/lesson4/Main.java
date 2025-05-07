package src.lesson4;

interface Swimming{
    void swim();
}




public class Main {
    public static void main(String[] args) {

        Swimming s1 = new Swimming(){
            @Override
            public void swim() {
                System.out.println("Student swim");
            }
        };
        go(s1);

        Swimming t1 = new Swimming(){
            @Override
            public void swim() {
                System.out.println("Teacher swim");
            }
        };
        go(t1);
    }
    public static void go(Swimming s){
        System.out.println("starting----");
        s.swim();
    }
}