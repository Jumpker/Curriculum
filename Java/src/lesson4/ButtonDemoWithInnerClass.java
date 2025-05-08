package src.lesson4;

interface OnClickListener {
    void onClick();
}


public class ButtonDemoWithInnerClass {
    public static void main(String[] args) {
        OnClickListener button = new OnClickListener() {
            @Override
            public void onClick() {
                System.out.println("按钮被点击了！来自匿名内部类");
            }
        };
        button.onClick();
    }
}
