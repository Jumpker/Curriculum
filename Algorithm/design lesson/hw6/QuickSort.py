import random
import time

# 交换数组中的两个元素
def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]

# 分区：将数组分为两部分，左边小于pivot，右边大于pivot，也是排序的实际操作
def partition(arr, low, high):
    pivot = arr[high]               # 选择最后一个元素作为pivot
    i = low - 1                     # i是小于pivot的元素的边界

    # 遍历数组，将小于pivot的元素移到左边
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1                  # 增加小于pivot的元素的边界
            swap(arr, i, j)         # 交换当前元素到左边区域

    # 将所有小于pivot的元素都在其左边
    swap(arr, i + 1, high)
    return i + 1                    # 返回pivot的最终位置

# 快排
def quick_sort(arr, low, high):
    if low < high:                  # 递归终止条件：子数组长度大于1
        # 获取分区点
        pi = partition(arr, low, high)
        
        # 递归排序左半部分（小于pivot的元素）
        quick_sort(arr, low, pi - 1)
        
        # 递归排序右半部分（大于pivot的元素）
        quick_sort(arr, pi + 1, high)

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
    quick_sort(arr5, 0, 4)
    print("排序后数组: ", end="")
    print_array(arr5)
    print()
    
    # 测试长度为10的数组
    arr10 = generate_random_array(10)
    print("长度为10的原始数组: ", end="")
    print_array(arr10)
    quick_sort(arr10, 0, 9)
    print("排序后数组: ", end="")
    print_array(arr10)
    print()
    
    # 测试长度为100的数组
    arr100 = generate_random_array(100)
    print("长度为100的原始数组: ", end="")
    print_array(arr100)
    quick_sort(arr100, 0, 99)
    print("排序后数组: ", end="")
    print_array(arr100)

# Time Complexity: O(nlogn)
# Space Complexity: O(logn)
# Stability: N

if __name__ == "__main__":
    main()