def best_merge(counts):
    """
    type: list[int]
    rtype: List[int]

    最优合并问题
    counts是一个列表，存储k个序列s1,s2,...,sk的长度，
    返回合并这个序列使所需要的总比较次数最少的最优合并顺序（以int列表形式，元素为counts序列中元素的索引）

    既然每两个序列合并均需要m+n-1次比较，那么我们需要长度短的序列尽可能早地被合并。因为每次合并两个序列时，它们的长度会参与后续所有合并的 "成本计算"
    因此我们可以遵循如下步骤：
    1. 每次从所有未合并的序列中，选出长度最短的两个序列。
    2. 合并这两个序列，计算本次合并的比较次数（m+n-1），并累加到总次数中。
    3. 将合并后的新序列（长度为 m+n）放回未合并序列集合中，重复步骤 1-2，直到只剩一个序列。
    """
    if(len(counts) == 1):    #只有一个序列，返回1
        return [1]

    # 结果列表，存储合并顺序（只包含原始序列的索引）
    res = []
    
    # 创建一个包含序列长度和原始索引的列表
    # 每个元素是一个元组：(长度, 原始索引)
    sequences = [(length, i) for i, length in enumerate(counts)]
    
    # 当还有多于一个序列时，继续合并
    while len(sequences) > 1:
        # 按照序列长度排序
        sequences.sort(key=lambda x: x[0])
        
        # 获取最短的两个序列
        seq1, seq2 = sequences[0], sequences[1]
        
        # 当索引是原始序列的索引时（非负数），添加到结果中
        if seq1[1] >= 0:
            res.append(seq1[1] + 1)         #题目索引从1开始，这里加1
        if seq2[1] >= 0:
            res.append(seq2[1] + 1)
        
        # 计算合并后的新序列长度：两个序列长度之和减1
        merged_length = seq1[0] + seq2[0] - 1
        
        # 从序列列表中移除这两个序列
        sequences.pop(0)
        sequences.pop(0)
        
        # 将合并后的新序列添加回列表
        # 使用一个不存在的索引（-1）作为占位符，因为这是一个新的合并序列
        sequences.append((merged_length, -1))
    
    return res


if __name__ == '__main__':
    import time
    
    start_time = time.time()
    
    print(best_merge([2, 3, 5, 10]))
    print(best_merge([34, 23, 2, 10, 64]))
    print(best_merge([22, 21, 20, 19]))
    print(best_merge([34,22]))
    print(best_merge([34]))
    print(best_merge([]))
    
    end_time = time.time()
    print(f"程序执行时间：{end_time - start_time:.6f}秒")