package src.lesson2;

class Car {
    private String CarName;
    Car(){
        this.CarName = CarName;
    }
    public String getCarName(){
        return CarName;
    }
    public void tools(){
        System.out.println("我们有空车");
    }

    public class Engine extends Car{
        private Car car;
        public Engine(){
            super();
            this.car = car;
        }
        @Override
        public void tools(){
            System.out.println("空车加装了引擎");
        }
    }
}
