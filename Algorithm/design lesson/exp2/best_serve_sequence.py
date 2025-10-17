def best_serve_sequence(customers, s=1):
    """
    type customers: list[int]
    type s: int
    rtype: tuple(List[int], float)

    最优服务次序问题（实际上是一个作业调度问题，基于贪心策略我们可以直接用短作业优先算法）
    customers是一个列表，存储n个顾客需要的服务时间t1,t2,...,tn，
    s是可以提供服务的窗口数量，
    返回使平均等待时间达到最小的顾客服务次序（以int列表形式，元素为customers列表中元素的索引+1）和平均等待时间（浮点数）

    为了使平均等待时间最小，我们需要让服务时间短的顾客优先得到服务。
    因为每个顾客的等待时间取决于在他之前所有顾客的服务时间总和。
    如果按照服务时间从小到大的顺序安排顾客，可以使总等待时间最小，从而使平均等待时间最小。
    当有多个服务窗口时，我们可以采用以下贪心策略：
    1. 将顾客按照服务时间从小到大排序
    2. 依次将顾客分配到当前结束时间最早的窗口
    3. 返回顾客的服务次序和平均等待时间
    """

    if s == 1:  # 只有一个服务窗口的情况
        # 创建一个包含服务时间和原始索引的列表
        # 每个元素是一个元组：(服务时间, 原始索引)
        indexed_customers = [(time, i) for i, time in enumerate(customers)]
        
        # 按照服务时间从小到大排序
        indexed_customers.sort(key=lambda x: x[0])
        
        # 计算每个顾客的等待时间
        wait_times = []
        current_wait = 0
        
        for time, _ in indexed_customers:
            wait_times.append(current_wait)
            current_wait += time
        
        # 计算平均等待时间
        avg_wait_time = sum(wait_times) / len(customers) if customers else 0
        
        # 返回排序后的顾客索引+1（因为题目要求从1开始）和平均等待时间
        return [index + 1 for _, index in indexed_customers], avg_wait_time

    else:  # 多个服务窗口的情况
        # 创建一个包含服务时间和原始索引的列表
        indexed_customers = [(time, i) for i, time in enumerate(customers)]
        
        # 按照服务时间从小到大排序
        indexed_customers.sort(key=lambda x: x[0])
        
        # 初始化每个窗口的结束时间
        window_end_times = [0] * s
        
        # 顾客的服务次序和等待时间
        service_order = [0] * len(customers)
        wait_times = [0] * len(customers)
        
        # 依次将顾客分配到当前结束时间最早的窗口
        for time, index in indexed_customers:
            # 找到当前结束时间最早的窗口
            earliest_window = window_end_times.index(min(window_end_times))
            
            # 记录顾客的等待时间（窗口当前的结束时间）
            wait_times[index] = window_end_times[earliest_window]
            
            # 更新该窗口的结束时间
            window_end_times[earliest_window] += time
            
            # 记录顾客的服务次序
            service_order[index] = index + 1
        
        # 计算平均等待时间
        avg_wait_time = sum(wait_times) / len(customers) if customers else 0
        
        return service_order, avg_wait_time


if __name__ == '__main__':
    import time
    
    start_time = time.time()
    
    # 测试用例
    order, avg_wait = best_serve_sequence([5, 3, 8, 2, 1])  # 单窗口
    print(f"服务次序: {order}, 平均等待时间: {avg_wait}")
    
    order, avg_wait = best_serve_sequence([5, 3, 8, 2, 1], s=2)  # 双窗口
    print(f"服务次序: {order}, 平均等待时间: {avg_wait}")
    
    order, avg_wait = best_serve_sequence([10, 5, 8, 7, 4, 2, 1, 6, 9, 3], s=3)  # 三窗口
    print(f"服务次序: {order}, 平均等待时间: {avg_wait}")
    
    end_time = time.time()
    print(f"程序执行时间：{end_time - start_time:.6f}秒")