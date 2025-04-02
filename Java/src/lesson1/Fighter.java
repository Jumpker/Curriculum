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

    public int getHealth() {
        return health;
    }

    public String getName() {
        return name;
    }

    public void attacked(Fighter attacker){
        int damage = Math.max(0, attacker.damagePerAttack-this.protection+rand.nextInt(5));
        this.health -= damage;
        if(this.health < 0) this.health = 0;
        System.out.println(attacker.name + " hit " + this.name + " for " + damage + " damage, remaining health " + this.health);
    }
}
