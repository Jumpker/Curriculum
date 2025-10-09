#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 交换两个整数的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 构造大根堆
void heapify(int arr[], int n, int i) {
    int largest = i; // 父节点存储位置（当前数）
    int left = 2 * i + 1; // 左子节点存储位置
    int right = 2 * i + 2; // 右子节点存储位置

    // 如果左子节点存在且大于当前最大值，则更新最大值索引
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点存在且大于当前最大值，则更新最大值索引
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值不是当前父节点，则交换并递归调整堆
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序
void HeapSort(int arr[], int n) {
    // 构建初始大根堆（从最后一个非叶子节点开始向上调整）
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 逐个将堆顶元素（最大值）与末尾元素交换，并重新调整堆
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // 将当前最大元素（堆顶）与末尾元素交换
        heapify(arr, i, 0); // 重新调整剩余元素构成大根堆
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



// 生成随机数组
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000000; // 生成0到10^9-1的随机数
    }
}

int main() {
    srand(time(NULL)); // 初始化随机数种子
    
    // 测试长度为5的数组
    int arr5[5];
    generateRandomArray(arr5, 5);
    printf("长度为5的原始数组: ");
    printArray(arr5, 5);
    HeapSort(arr5, 5);
    printf("排序后数组: ");
    printArray(arr5, 5);
    printf("\n");
    
    // 测试长度为10的数组
    int arr10[10];
    generateRandomArray(arr10, 10);
    printf("长度为10的原始数组: ");
    printArray(arr10, 10);
    HeapSort(arr10, 10);
    printf("排序后数组: ");
    printArray(arr10, 10);
    printf("\n");
    
    // 测试长度为100的数组
    int arr100[100];
    generateRandomArray(arr100, 100);
    printf("长度为100的原始数组(前10个元素): ");
    printArray(arr100, 10); // 只打印前10个元素
    HeapSort(arr100, 100);
    printf("排序后数组(前10个元素): ");
    printArray(arr100, 10);
    
    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Stability: N