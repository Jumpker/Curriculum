#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 合并数组的两个子数组
void merge(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // 复制数据
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // 初始索引，L和R
    int i = 0;
    int j = 0;

    // 初始索引，用于合并后的子数组
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制 L[] 中剩余的元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 复制 R[] 中剩余的元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 释放动态分配的内存
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
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
    mergeSort(arr5, 0, 4);
    printf("排序后数组: ");
    printArray(arr5, 5);
    printf("\n");
    
    // 测试长度为10的数组
    int arr10[10];
    generateRandomArray(arr10, 10);
    printf("长度为10的原始数组: ");
    printArray(arr10, 10);
    mergeSort(arr10, 0, 9);
    printf("排序后数组: ");
    printArray(arr10, 10);
    printf("\n");
    
    // 测试长度为100的数组
    int arr100[100];
    generateRandomArray(arr100, 100);
    printf("长度为100的原始数组: ");
    printArray(arr100, 100);
    mergeSort(arr100, 0, 99);
    printf("排序后数组: ");
    printArray(arr100, 100);
    
    return 0;
}