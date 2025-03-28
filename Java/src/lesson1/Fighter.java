package src.lesson1;

import java.util.Random;

public class Fighter {
    private int health;
    private int damagePerAttack;
    private String name;
    private int protection;
    Random rand = new Random();

    public Fighter(String name, int health, int damagePerAttack, int protection) {
        this.name = name;
        this.health = health;
        this.damagePerAttack = damagePerAttack;
        this.protection = protection;
    }

    public void attack(Fighter attacker){
        int damage = Math.max(0, attacker.damagePerAttack-this.protection+rand.nextInt(5));

    }
}
