#include <stdio.h>
#define N 20

int main() {
    int arr[N];
    int n = 0;
    // 读取输入，直到文件结束或达到N个元素
    while (n < N && scanf("%d", &arr[n]) == 1) {
        n++;
    }

    // 去重
    if (n > 0) {
        int unique_arr[N];
        int unique_count = 0;
        unique_arr[unique_count++] = arr[0];

        for (int i = 1; i < n; i++) {
            int is_duplicate = 0;
            for (int j = 0; j < unique_count; j++) {
                if (arr[i] == unique_arr[j]) {
                    is_duplicate = 1;
                    break;
                }
            }
            if (!is_duplicate) {
                unique_arr[unique_count++] = arr[i];
            }
        }

        // 输出去重后的数组
        for (int i = 0; i < unique_count; i++) {
            printf("%d", unique_arr[i]);
            if (i < unique_count - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}