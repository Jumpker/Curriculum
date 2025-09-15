def insertion_sort(array):
    for i in range(1, len(array)):      # 设第一个元素已有序，从第二个元素开始
        j = i
        while j > 0 and array[j] < array[j - 1]:    #后者小于前者，移到前面去
            swap(j, j - 1, array)
            j -= 1
    return array

def swap(i, j, array):
    array[i], array[j] = array[j], array[i]

# Time Complexity: O(n^2)
# Space Complexity: O(1)
# Stability: Y