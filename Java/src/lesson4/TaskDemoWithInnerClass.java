package src.lesson4;

interface OneTimeTask {
    void execute();
}

public class TaskDemoWithInnerClass {
    public static void runTask(OneTimeTask task)  {
        System.out.println("准备执行一次性任务...");
        task.execute(); // 执行任务
        System.out.println("任务执行完毕。");
        System.out.println("------------------");
    }
    public static void main(String[] args) {
        OneTimeTask task1 = new OneTimeTask(){ // 使用匿名内部类实现一次性任务
            @Override
            public void execute() {
                System.out.println("匿名内部类消息：Hello, World!");
            }
        };
        runTask(task1); // 执行任务1
        runTask(() -> {System.out.println("Lambda表达式消息：Hello, World!");});
    }
}
