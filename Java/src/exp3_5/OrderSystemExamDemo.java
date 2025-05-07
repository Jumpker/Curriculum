package src.exp3_5;

// 演示订单处理系统用法的类
public class OrderSystemExamDemo {
    public static void main(String[] args) {
        // 创建实物商品订单处理器实例
        PhysicalProductOrderHandler physicalOrder = new PhysicalProductOrderHandler("1234567890",
        "广东省 佛山市 三水区 云东海街道 学海路一号 广东财经大学",
        100, 8, 10);
        physicalOrder.processOrder();

        // 创建虚拟服务订单处理器实例
        VirtualServiceOrderHandler virtualOrder = new VirtualServiceOrderHandler("0987654321", "云存储服务", "example@example.com", 50);
        virtualOrder.processOrder();
    }
}    