#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


//分区：将数组分为两部分，左边小于pivot，右边大于pivot，也是排序的实际操作
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为pivot
    int i = low - 1;        // i是小于pivot的元素的边界

    // 遍历数组，将小于pivot的元素移到左边
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // 增加小于pivot的元素的边界
            swap(&arr[i], &arr[j]);  // 交换当前元素到左边区域
        }
    }

    // 将所有小于pivot的元素都在其左边
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  // 返回pivot的最终位置
}

//快排
void quickSort(int arr[], int low, int high) {
    if (low < high) {  // 递归终止条件：子数组长度大于1
        // 获取分区点
        int pi = partition(arr, low, high);
        
        // 递归排序左半部分（小于pivot的元素）
        quickSort(arr, low, pi - 1);
        
        // 递归排序右半部分（大于pivot的元素）
        quickSort(arr, pi + 1, high);
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
    quickSort(arr5, 0, 4);
    printf("排序后数组: ");
    printArray(arr5, 5);
    printf("\n");
    
    // 测试长度为10的数组
    int arr10[10];
    generateRandomArray(arr10, 10);
    printf("长度为10的原始数组: ");
    printArray(arr10, 10);
    quickSort(arr10, 0, 9);
    printf("排序后数组: ");
    printArray(arr10, 10);
    printf("\n");
    
    // 测试长度为100的数组
    int arr100[100];
    generateRandomArray(arr100, 100);
    printf("长度为100的原始数组: ");
    printArray(arr100, 100);
    quickSort(arr100, 0, 99);
    printf("排序后数组: ");
    printArray(arr100, 100);
    
    return 0;
}

//Time Complexity: O(nlogn)
//Space Complexity: O(logn)
//Stability: N