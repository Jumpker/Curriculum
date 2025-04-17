package src.lesson2.Fighter;

import java.util.Random;

import static java.lang.Math.abs;

class Fighter {
    protected String name;
    protected int health;
    protected int attackPower;
    protected int defense;

    public Fighter(String name){
        this.name = name;
        this.health = 100;
        this.attackPower = 20;
        this.defense = 10;
    }
    public  boolean isAlive() {
        return health > 0;
    }

    public void showStates(){
        System.out.println(name + " - " + "HP：" + health + " | " + "Attack：" + attackPower + " | " + "Defense：" + defense);
    }

    public void attack(Fighter target) {
    }
}
//-----------------------------------------------------------------------------------
class assassin extends Fighter {
    public assassin(String name){
        super(name);
        super.attackPower += 3;
        super.defense -= 3;
        super.health -= 10;
    }
    @Override
    public void attack(Fighter target) {
        boolean flag = false;
        int damage = this.attackPower;
        Random random = new Random();
        if(random.nextInt(100) <= 30){
            damage *= 2;
            flag = true;
        }
        if(target.defense > damage) damage = 0;
        else {
            target.health -= damage - target.defense;
            //
        }
        System.out.println(name + " 攻击了 " + target.name + "，造成了 " + (damage - target.defense) + " 点" + ((flag)?"暴击":"") + "伤害 ");
    }
}
//-----------------------------------------------------------------------------------
class warrior extends Fighter {
    public warrior(String name){
        super(name);
        super.health += 10;
        super.attackPower += 3;
        super.defense += 1;
    }
    @Override
    public void attack(Fighter target) {
        int damage = this.attackPower+5;
        if(target.defense > damage) damage = 0;
        else {
            target.health -= damage - target.defense;
            //
        }
        System.out.println(name + " 攻击了 " + target.name + "，造成了 " + (damage - target.defense) + " 点伤害 ");
    }
}
//---------------------------------------------------------------------------------------------------
class wizard extends Fighter {
    public wizard(String name){
        super(name);
        super.health -= 5;
        super.attackPower += 5;
        super.defense -= 3;
    }

    public void attackAOE(Fighter target1, Fighter target2) {
        boolean flag = false;
        int damage = this.attackPower;
        Random random = new Random();
        if(random.nextInt(100) <= 30){
            flag = true;
        }
        if(target1.defense > damage) damage = 0;
        else {
            target1.health -= (damage - target1.defense);
            //
        }
        System.out.println(name + " 攻击了 " + target1.name + "，造成了 " + (damage - target1.defense) + " 点伤害 ");
        if(flag){
            if(target2.defense > damage) damage = 0;
            else {
                target2.health -= damage - target2.defense;
                //
            }
            System.out.println(name + " 产生AOE伤害同时攻击了 " + target2.name + "，造成了 " + (damage - target2.defense) + " 点伤害 ");
        }
    }
}
//======================================================================================================

public class FighterGame{
    public static void main(String[] args) {
        Fighter[] fighter = new Fighter[]{
                new assassin("艾吉奥"),
                new warrior("康纳")};
        wizard wizard = new wizard("爱德华");
        while (fighter[0].isAlive() && fighter[1].isAlive() && wizard.isAlive()) {
            Random random1 = new Random();
            Random random2 = new Random();
            int i = random1.nextInt(3);
            int j = random2.nextInt(2);
            if(i==0) fighter[0].attack((j==0)?fighter[1]:wizard);
            else if(i==1) fighter[1].attack((j==1)?wizard:fighter[0]);
            else if(i==2) wizard.attackAOE(fighter[j], fighter[abs(j-1)]);
            System.out.println("当前状态：");
            fighter[0].showStates();
            fighter[1].showStates();
            wizard.showStates();
            System.out.println();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
