def save_programs(ls, L):
    """
    type ls: list[int]
    type L: int
    rtype: List[int]

    程序存储问题，设有n 个程序{1,2,…,n }要存放在长度为L的磁带上。程序i存放在磁带上的长度是li (1≤i≤n)
    输入ls列表，表示程序i的所需的磁带长度
    返回程序在磁带上的存储方案（原ls索引构成的列表res）

    既然要存储尽可能多的程序，且磁带长度为L不变，那我们只要先把短的程序存起来就好了
    """

    if(len(ls) == 1):    #只有一个程序，返回1
        return [1]

    res = []                # 结果列表，存储合并顺序（只包含原始序列的索引）
    current_length = 0      # 已放入磁带的程序长度
    min_length = float('inf')  # 当前剩余程序中长度最短的程序长度，初始设为无穷大
    min_index = 0           # 当前剩余程序中长度最短的程序的索引
    count = 0               # 已放入磁带的程序数量

    while current_length < L:

        # 找到当前剩余程序中长度最短的程序
        for i in range(len(ls)):
            if (ls[i] > 0 and ls[i] < min_length):
                min_length = ls[i]
                min_index = i

        # 如果当前已放入磁带的程序长度加上最短程序的长度超过了磁带长度L  或   已全部放入磁带
        if (current_length + min_length > L or count == len(ls)):
            break
        # 将其放入磁带
        res.append(min_index + 1)
        current_length += min_length
        # 标记已放入磁带的程序（长度为-1）
        ls[min_index] = -1
        min_length = float('inf')
        count += 1
    return res


if __name__ == '__main__':
    import time
    
    start_time = time.time()
    
    L = 100
    print(save_programs([5, 13, 17, 35, 50], L))
    print(save_programs([25, 20, 30, 40, 50], L))
    print(save_programs([10], L))
    print(save_programs([], L))
    print(save_programs([40, 50, 10], L))
    
    end_time = time.time()
    print(f"程序执行时间：{end_time - start_time:.6f}秒")
