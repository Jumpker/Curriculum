package src.lesson1;

public class Main {
    public static void main(String[] args) {
        String winner;
        Fighter f1 = new Fighter("张三", 100, 11, 6);
        Fighter f2 = new Fighter("李四", 120, 8, 8);
        while (f1.getHealth()!=0 && f2.getHealth()!=0) {
            f2.attacked(f1);
            if(f2.getHealth()==0) break;
            f1.attacked(f2);
        }
        if(f1.getHealth()==0) {
            winner = f2.getName();
        } else {
            winner = f1.getName();
        }
        System.out.println(winner + " 获胜");
    }
}
