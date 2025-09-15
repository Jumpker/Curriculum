def SelectionSort(array):
    currentIdx = 0
    while currentIdx < len(array) - 1:      #依次遍历，当前索引的左边是有序
        smallestIdx = currentIdx
        for i in range(currentIdx + 1, len(array)): #依次遍历，找到最小的索引
            if array[smallestIdx] > array[i]:
                smallestIdx = i
        swap(currentIdx, smallestIdx, array)    #与无序的第一个（当前索引）交换
        currentIdx += 1
    return array

def swap(i, j, array):
    array[i], array[j] = array[j], array[i]

# Time Complexity: O(n^2)
# Space Complexity: O(1)
# Stability: N