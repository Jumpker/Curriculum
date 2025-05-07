package src.exp3;


interface Processable{
    public void processOrder();                 //启动订单的整个处理过程
    public String  getOrderStatus();            //获取订单处理状态
}

abstract class AbstractOrderHandler implements Processable{     //提供了一个基础框架，包含了通用的属性和行为
    private String orderId;
    private String Status;
    private double Amount;

    public AbstractOrderHandler(String orderId){                //构造函数
        this.orderId = orderId;
        this.Amount = calculateTotalAmount();
        if (Amount>0) this.Status = "NEW";
        else this.Status = "FAILED";
    }
    public String getOrderId(){
        return orderId;
    }
    public boolean validateOrder(){                             //检查订单总金额是否大于零，并且初始状态不是 FAILED
        return (this.Amount > 0 &&  this.Status != "FAILED");
    }
    public String getOrderStatus(){
        return Status;
    }
    public void setStatus(String status){
        this.Status = status;
    }
    public void processOrder(){
        if(Status != "NEW"){
            Status  = "FAILED";
            return;
        }
        if(validateOrder()){
            if(executeSpecificProcessing()){
                Status = "COMPLETED";
                if(!sendConfirmation()){
                    Status = "FAILED";
                }
            }
            else{
                Status = "FAILED";
            }
        }
    }

    public abstract double calculateTotalAmount();              //定义订单处理流程中的“计算总金额”这一步骤
    public abstract boolean executeSpecificProcessing();        //定义订单处理流程中的“执行特定处理”这一步骤
    public abstract boolean sendConfirmation();                 //定义订单处理流程中的“发送确认”这一步骤
}

class PhysicalOrderHandler extends AbstractOrderHandler{
    private String adress;
    private double productPrice;
    private int quantity;
    private static int productQuantity = 10;
    public PhysicalOrderHandler(String orderId, String adress, double productPrice, int quantity){
        super(orderId);
        this.adress = adress;
        this.productPrice = productPrice;
        this.quantity = quantity;
//调用父类构造函数
        }
    @Override
    public double calculateTotalAmount(){
        return productPrice * quantity;
    }
    @Override
    public boolean executeSpecificProcessing(){
        System.out.println("开始处理订单：");
        if (quantity <= productQuantity) {
            productQuantity -= quantity;
            System.out.println("发货成功，将商品寄送到：" + adress);
            System.out.println("成功处理订单：" + super.getOrderId());
            super.setStatus("PROCESSING");
            return true;
        }
        System.out.println("商品数量不足，无法处理订单：" + super.getOrderId());
        super.setStatus("FAILED");
        return false;
    }
    @Override
    public boolean sendConfirmation(){
        if(super.getOrderStatus() == "PROCESSING") {
            System.out.println("开始发送确认邮件：");
            System.out.println("成功发送确认邮件：" + super.getOrderId());
            return true;
        }
        return false;
    }
}

