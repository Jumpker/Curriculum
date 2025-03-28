package src.exp1;

public class WanNumber{
    public static void main(String[] args) {
        for(int i=1; i<=1000; i++) {
            if(sum_yin(yin(i))==i) System.out.println(i);
        }
    }

    public static int[] yin(int n){                         //得到一个数的所有因子
        int[] yin = new int[n];
        int j = 0;
        for(int i=1; i<=n; i++){
            if(i==n) yin[j] = -1;
            else if(n%i==0){
                yin[j++] = i;
            }
        }
        return yin;
    }
    public static int sum_yin(int[]yin) {                   //这里得出该数的因子之和
        int sum=0;
        for(int i=0; yin[i]!=-1; i++){
            sum+=yin[i];
        }
        return sum;
    }
}