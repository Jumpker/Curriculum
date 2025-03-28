package src.exp2.Rectangle;

public class Rectangle {
    private double width;
    private double height;
    private String color;

    Rectangle(){
        this.width = 1.0;
        this.height = 1.0;
        this.color = "白色";
    }

    Rectangle(double width, double height, String color){
        this.width = width;
        this.height = height;
        this.color = "白色";
    }

    double getWidth(){
        return this.width;
    }

    double getHeight(){
        return this.height;
    }

    String getColor(){
        return this.color;
    }

    void setWidth(double width){
        this.width = width;
    }

    void setHeight(double height){
        this.height = height;
    }

    void setColor(String color){
        this.color = color;
    }

    double getArea(){
        return this.width * this.height;
    }

    double getPerimeter(){
        return 2 * (this.width + this.height);
    }
}
