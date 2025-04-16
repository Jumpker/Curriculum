package src.exp3;


import static java.lang.Math.abs;

public class Pointer {


    public static void main(String[] args) {
        pointer1 p1 = new pointer1(1.0,2.0);
        pointer1 p2 = new pointer1(3.0,4.0);
        System.out.println("两点间的距离为：" + p1.distance(1.0,2.0,3.0,4.0));
        System.out.println("两点中点的坐标为： (" +
                (abs((p1.getX()-p2.getX())/2) + p1.getX()) + "," +
                (abs((p1.getY()-p2.getY())/2) + p1.getY()) + ")");
    }


}
class pointer1{
    private double x,y;
    public pointer1(double x,double y) {
        this.x=x;
        this.y=y;
    }
    public void setX(double x){
        this.x=x;
    }
    public void setY(double y){
        this.y=y;
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    public void display(){
        System.out.println("("+x+","+y+")");
    }
    @Override
    public String toString() {
        return "("+x+","+y+")";
    }
    @Override
    public boolean equals(Object obj){
        if(this==obj)
            return true;
        if(obj==null)
            return false;
        if(this.getClass()!=obj.getClass())
            return false;
        pointer1 p=(pointer1)obj;
        if(this.x==p.x&&this.y==p.y)
            return true;
        else
            return false;
    }
    public double distance(double x1,double y1, double x2, double y2){
        return (double) Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
}