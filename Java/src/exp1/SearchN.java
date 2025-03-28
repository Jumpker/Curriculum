package src.exp1;

public class SearchN {
    public static void main(String[] args){
        int i = 1;
        while(sum_fact(i)<=9999) i++;
        System.out.println(i-1);
    }
    public static int fact(int n){                  //求n的阶乘
        int fact = 1;
        for(int i=1; i<=n; i++){
            fact *= i;
        }
        return fact;
    }
    public static int sum_fact(int n){
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum += fact(i);
        }
        return sum;
    }
}