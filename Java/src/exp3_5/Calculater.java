package src.exp3_5;

interface Calculable {
    public double calculateArea();
    public double calculatePerimeter();
}

abstract class AbstractShape implements Calculable {
    private String shapeName;
    public AbstractShape(String shapeName) {
        this.shapeName = shapeName;
    }
    @Override
    public abstract double calculateArea();
    @Override
    public abstract double calculatePerimeter();
    String getShapeName() {
        return shapeName;
    }
}

class Circle extends AbstractShape {
    private double radius;
    public Circle(String shapeName, double radius) {
        super(shapeName);
        if (radius <= 0) throw new IllegalArgumentException("半径必须为正数");
        this.radius = radius;
    }
    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
    @Override
    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
    public double getRadius() {
        return radius;
    }
}


class Rectangle extends AbstractShape {
    private double width;
    private double height;
    public Rectangle(String shapeName, double width, double height) {
        super(shapeName);
        this.width = width;
        this.height = height;
    }
    @Override
    public double calculateArea() {
        return width * height;
    }
    @Override
    public double calculatePerimeter(){
        return 2 * (width + height);
    }
    public double getWidth() {
        return width;
    }
    public double getHeight() {
        return height;
    }
 }


 public class Calculater{
    public static void main(String[] args) {
        System.out.println("---计算圆形---");
        Circle circle = new Circle("Circle", 5.0);
        System.out.println("图形名称：" + circle.getShapeName());
        System.out.println("半径：" + circle.getRadius());
        System.out.println("面积：" + circle.calculateArea());
        System.out.println("周长：" + circle.calculatePerimeter() + '\n');

        System.out.println("---计算矩形---");
        Rectangle rectangle = new Rectangle("Rectangle", 4.0, 6.0);
        System.out.println("图形名称：" + rectangle.getShapeName());
        System.out.print("宽度：" + rectangle.getWidth() + '，');
        System.out.println("高度：" + rectangle.getHeight());
        System.out.println("面积：" + rectangle.calculateArea());
        System.out.println("周长：" + rectangle.calculatePerimeter() + '\n');

        System.out.println("---尝试计算无效半径的圆形---");
        try {
            Circle circle2 = new Circle("Circle", -5.0);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
 }