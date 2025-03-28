package src.exp2.MyInteger;

public class MyInteger{
    private int value;

    public MyInteger(int value){
        this.value = value;
    }

    public int getInt(){
        return value;
    }

    public boolean isEven(){
        return value % 2 == 0;
    }

    public boolean isOdd(){
        return value % 2 != 0;
    }

    public boolean isPrime(){
        for(int i = 2; i*i < value; i++){
            if(value % i == 0){
                return false;
            }
        }
        return true;
    }

    public boolean equals(int x) {
        return value == x;
    }

    public int parseInt(String x){
        return Integer.parseInt(x);
    }
}
