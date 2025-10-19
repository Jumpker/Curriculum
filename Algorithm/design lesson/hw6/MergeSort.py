import random
import time

# 合并数组的两个子数组
def merge(arr, left, right):
    mid = left + (right - left) // 2
    n1 = mid - left + 1
    n2 = right - mid

    # 创建临时数组
    L = [0] * n1
    R = [0] * n2

    # 复制数据
    for i in range(n1):
        L[i] = arr[left + i]
    for j in range(n2):
        R[j] = arr[mid + 1 + j]

    # 初始索引，L和R
    i = 0
    j = 0

    # 初始索引，用于合并后的子数组
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # 复制 L[] 中剩余的元素
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # 复制 R[] 中剩余的元素
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2

        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, right)

# 打印数组
def print_array(arr):
    print(' '.join(map(str, arr)))

# 生成随机数组
def generate_random_array(n):
    return [random.randint(0, 100 - 1) for _ in range(n)]

def main():
    random.seed(int(time.time()))  # 初始化随机数种子
    
    # 测试长度为5的数组
    arr5 = generate_random_array(5)
    print("长度为5的原始数组: ", end="")
    print_array(arr5)
    merge_sort(arr5, 0, 4)
    print("排序后数组: ", end="")
    print_array(arr5)
    print()
    
    # 测试长度为10的数组
    arr10 = generate_random_array(10)
    print("长度为10的原始数组: ", end="")
    print_array(arr10)
    merge_sort(arr10, 0, 9)
    print("排序后数组: ", end="")
    print_array(arr10)
    print()
    
    # 测试长度为100的数组
    arr100 = generate_random_array(100)
    print("长度为100的原始数组: ", end="")
    print_array(arr100)
    merge_sort(arr100, 0, 99)
    print("排序后数组: ", end="")
    print_array(arr100)

if __name__ == "__main__":
    main()