package src.exp3;

import java.util.Scanner;

class SA {
    public int f(int a, int b){
        int res = 1;
        for(int i=1; i<=a && i<=b; i++){
            if(a%i==0 && b%i==0) res = i;
        }
        return res;
    }
}

class SB extends SA{
    @Override
    public int f(int a,int b){
        return (a*b)/super.f(a,b);
    }
}


public class shu {
    public static void main(String[] args) {
        SA shu1 = new SA();
        int a=4, b=6;
        System.out.println(shu1.f(a,b));
        SB shu2 = new SB();
        System.out.println(shu2.f(a,b));
    }
}