package src.exp3_5;

class VirtualServiceOrderHandler extends AbstractOrderHandler {
    private String serviceName;
    private String userEmail;
    private double servicePrice;

    // 修正：将 super() 调用移至构造函数第一行
    public VirtualServiceOrderHandler(String orderId, String serviceName, String userEmail, double servicePrice) {
        super(orderId); // 必须作为构造函数的第一条语句
        this.serviceName = serviceName;
        this.userEmail = userEmail;
        this.servicePrice = servicePrice;
    }

    @Override
    public double calculateTotalAmount() {
        return servicePrice; // 此时 servicePrice 已正确赋值
    }

    // 其他方法（与原代码一致）
    @Override
    public boolean executeSpecificProcessing() {
        System.out.println("开始处理虚拟服务订单：" + getOrderId());
        System.out.println("激活服务：" + serviceName + " 给用户邮箱：" + userEmail);
        System.out.println("更新用户账户信息...");
        setStatus("PROCESSING");
        return true;
    }

    @Override
    public boolean sendConfirmation() {
        if ("PROCESSING".equals(getOrderStatus())) {
            System.out.println("开始发送确认邮件...");
            System.out.println("成功发送已激活确认邮件！到邮箱：" + userEmail);
            setStatus("COMPLETED");
            return true;
        }
        return false;
    }
}