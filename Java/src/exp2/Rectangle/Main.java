package src.exp2.Rectangle;

public class Main {
    public static void main(String[] args){
        Rectangle r1 = new Rectangle(4.0, 40.0, "黄色");
        Rectangle r2 = new Rectangle(3.5, 35.9, "红色");

        System.out.println("\nr1:\n宽度为：" + r1.getWidth() +
                "\n高度为：" + r1.getHeight() +
                "\n颜色为：" + r1.getColor() +
                "\n面积：" + r1.getArea() +
                "\n周长：" + r1.getPerimeter());

        System.out.println("\nr2:\n宽度为：" + r2.getWidth() +
                "\n高度为：" + r2.getHeight() +
                "\n颜色为：" + r2.getColor() +
                "\n面积：" + r2.getArea() +
                "\n周长：" + r2.getPerimeter());
    }
}
