def BubbleSort(array):          #冒泡排序（优化）
    isSorted = False            #先设置flag为False，未完全有序
    counter = 0
    while not isSorted:         #排序算法
        isSorted = True
        for i in range(len(array) - 1 - counter):
            if array[i] > array[i + 1]:
                swap(i, i + 1, array)
                isSorted = False    #有交换说明还未完全有序
        counter += 1            #从前往后冒泡，后面的已有序，不再比较
    return array


def swap(i, j, array):              #交换数组中的两元素
    array[i], array[j] = array[j], array[i]


# Time Complexity: O(n^2)
# Space Complexity: O(1)
# Stability: Y