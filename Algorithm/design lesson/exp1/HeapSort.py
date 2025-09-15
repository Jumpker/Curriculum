def heapify(arr, n, i):             #构造大根堆
    largest = i                     #父节点存储位置（当前数）
    left = 2 * i + 1                #左子节点存储位置
    right = 2 * i + 2               #右子节点存储位置
    if left < n and arr[left] > arr[largest]:           #限定左子节点小于数组长度(后面不赘述)，并且左子节点数大于当前数，跳转到左子节点
        largest = left
    if right < n and arr[right] > arr[largest]:         #同理，跳转到右子节点
        largest = right
    if largest != i:                                    #当前数被挪了，说明当前数不是最大，把目前的最大数(上面跳转过，所以largest已不是原节点)挪到当前数的位置
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)                        #递归，继续构造大根堆

def HeapSort(arr):                     #堆排序
    n = len(arr)
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
    return arr

#Time Complexity: O(nlogn)
#Space Complexity: O(1)
#Stability: N