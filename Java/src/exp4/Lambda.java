package src.exp4;

interface LambdaInterface {
    void doSth();
}

public class Lambda {
    public static void main(String[] args) {
        LambdaInterface lambdaInterface = new LambdaInterface() {
            @Override
            public void doSth() {
                System.out.println("Hello Lambda!");
            }
        };
    }
}
