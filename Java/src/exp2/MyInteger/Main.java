package src.exp2.MyInteger;

public class Main {
    public static void main(String[] args) {
        int x = 10086;
        MyInteger myInteger = new MyInteger(x);
        System.out.println("\n你的整数是" + myInteger.getInt() +
                "\n它是不是偶数? " + myInteger.isEven() +
                "\n它是不是奇数? " + myInteger.isOdd() +
                "\n它是不是素数? " + myInteger.isPrime() +
                "\n它是否与10086相等? " + myInteger.equals(10086) +
                "\n随便找个字符串转换为整数: " + myInteger.parseInt("10086"));

    }
}
