package src.exp3_5;

// 定义订单处理接口，规定了订单处理的基本方法
interface Processable {
    // 启动订单的整个处理过程
    public void processOrder();
    // 获取订单处理状态
    public String getOrderStatus();
}