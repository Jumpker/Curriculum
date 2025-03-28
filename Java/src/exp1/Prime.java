package src.exp1;

public class Prime {
    public static void main(String[] args) {
        int n=1000, k=0;
        int[] prime = new int[169];
        prime[0] = 2;
        for (int i=3; i<n; i++) {                               //遍历2-根号n的所有数
            for (int j=0; j<=k && i%prime[j] != 0; j++) {       //若i无法整除哈希表中存储的所有素数
                if(j==k && i%prime[j] != 0){
                    prime[++k] = i;                             //将i添加进哈希表
                }
            }
        }
        for (int i=0; i<k; i++) {
            System.out.println(prime[i]);
        }
    }
}