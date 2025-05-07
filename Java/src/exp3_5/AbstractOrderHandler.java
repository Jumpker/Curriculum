package src.exp3_5;

// 抽象类，为订单处理器提供基础框架
abstract class AbstractOrderHandler implements src.exp3_5.Processable {
    private String orderId;
    private String status;
    // 移除 amount 字段，改为动态计算总金额

    // 构造函数，初始化订单处理器（不再调用 calculateTotalAmount()）
    public AbstractOrderHandler(String orderId) {
        this.orderId = orderId;
        this.status = "NEW"; // 初始状态默认设为 NEW，由 validateOrder 动态验证
        System.out.println("\n=============================================\n"
         + "正在初始化订单，订单号 " + orderId + "，初始状态: " + this.status);
    }

    // 获取订单 ID
    public String getOrderId() {
        return orderId;
    }

    // 验证订单是否有效（动态调用 calculateTotalAmount()）
    public boolean validateOrder() {
        return (calculateTotalAmount() > 0 && !"FAILED".equals(status));
    }

    // 获取订单状态
    public String getOrderStatus() {
        return status;
    }

    // 设置订单状态
    public void setStatus(String status) {
        this.status = status;
    }

    // 订单处理的模板方法，定义了订单处理的整体流程
    public final void processOrder() {
        if (!"NEW".equals(status)) {
            status = "FAILED";
            return;
        }
        if (validateOrder()) { // 动态验证总金额
            if (executeSpecificProcessing()) {
                if (!sendConfirmation()) {
                    status = "FAILED";
                }
            } else {
                status = "FAILED";
            }
        } else {
            status = "FAILED"; // 总金额无效时标记为失败
        }
        System.out.println("订单 " + orderId + " 最终状态: " + status + "\n=============================================\n");
    }

    // 抽象方法，由子类实现计算订单总金额
    public abstract double calculateTotalAmount();

    // 抽象方法，由子类实现订单的特定处理逻辑
    public abstract boolean executeSpecificProcessing();

    // 抽象方法，由子类实现发送订单确认信息
    public abstract boolean sendConfirmation();
}
