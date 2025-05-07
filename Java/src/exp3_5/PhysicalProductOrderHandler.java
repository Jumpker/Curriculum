package src.exp3_5;

// 处理实物商品订单的类
class PhysicalProductOrderHandler extends src.exp3_5.AbstractOrderHandler {
    private String shippingAddress;
    private double productPrice;
    private int quantity;
    private int productQuantity; // 改为实例变量（非static）

    // 构造函数新增初始库存参数
    public PhysicalProductOrderHandler(String orderId, String shippingAddress, double productPrice, int quantity, int initialProductQuantity) {
        super(orderId);
        this.shippingAddress = shippingAddress;
        this.productPrice = productPrice;
        this.quantity = quantity;
        this.productQuantity = initialProductQuantity; // 从外部传入初始库存
    }

    // 计算实物订单的总金额
    @Override
    public double calculateTotalAmount() {
        return productPrice * quantity;
    }

    // 执行实物订单的特定处理逻辑
    @Override
    public boolean executeSpecificProcessing() {
        System.out.println("开始处理实物订单：" + getOrderId());
        if (quantity <= productQuantity) {
            productQuantity -= quantity;
            System.out.println("发货成功，将商品寄送到：" + shippingAddress);
            System.out.println("成功处理订单：" + getOrderId());
            setStatus("PROCESSING");
            return true;
        }
        System.out.println("商品数量不足，无法处理订单：" + getOrderId());
        setStatus("FAILED");
        return false;
    }

    // 发送实物订单的确认信息
    @Override
    public boolean sendConfirmation() {
        if ("PROCESSING".equals(getOrderStatus())) {
            System.out.println("开始发送确认邮件...");
            System.out.println("成功发送确认邮件！订单号：" + getOrderId());
            setStatus("COMPLETED");
            return true;
        }
        return false;
    }
}