#include <stdio.h>
#include <stdlib.h>

// 自定义布尔类型以提高可移植性
typedef enum { false, true } bool;

// 马的 8 种可能移动方向
int mv[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

// 计算下一步的可用移动次数（Warnsdorff 规则）
int get_degree(int **Board, int Size, int x, int y) {
    int degree = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        if (nx >= 0 && nx < Size && ny >= 0 && ny < Size && Board[nx][ny] == 0) {
            degree++;
        }
    }
    return degree;
}

// 按可用移动次数排序的比较函数
int cmp(const void *a, const void *b) {
    int *ia = (int *)a;
    int *ib = (int *)b;
    int da = get_degree(NULL, 5, ia[0], ia[1]);
    int db = get_degree(NULL, 5, ib[0], ib[1]);
    return da - db;
}

bool DFS(int **Board, int Size, int x, int y, int step) {
    if (step == Size * Size) return true;
    Board[x][y] = step++;

    // 生成当前位置的所有合法下一步
    int next_moves[8][2];
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        if (nx >= 0 && nx < Size && ny >= 0 && ny < Size && Board[nx][ny] == 0) {
            next_moves[count][0] = nx;
            next_moves[count][1] = ny;
            count++;
        }
    }

    // 按可用移动次数升序排序（Warnsdorff 规则）
    qsort(next_moves, count, sizeof(next_moves[0]), cmp);

    for (int i = 0; i < count; i++) {
        if (DFS(Board, Size, next_moves[i][0], next_moves[i][1], step)) {
            return true;
        }
    }

    Board[x][y] = 0;
    return false;
}

int main() {
    int n = 5;
    int **Board = (int **)malloc(sizeof(int *) * n);
    if (Board == NULL) {
        printf("内存分配失败。\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        Board[i] = (int *)malloc(n * sizeof(int));
        if (Board[i] == NULL) {
            printf("内存分配失败。\n");
            // 释放之前分配的内存
            for (int j = 0; j < i; j++) {
                free(Board[j]);
            }
            free(Board);
            return 1;
        }
    }

    // 初始化棋盘
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Board[i][j] = 0;
        }
    }

    int x, y, step = 0;
    printf("请输入你的马的初始位置（坐标从 1 开始），用空格隔开：");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("输入无效，请输入两个整数。\n");
        // 释放内存
        for (int i = 0; i < n; i++) {
            free(Board[i]);
        }
        free(Board);
        return 1;
    }
    if (x < 1 || x > n || y < 1 || y > n) {
        printf("初始位置超出棋盘范围！\n");
        // 释放内存
        for (int i = 0; i < n; i++) {
            free(Board[i]);
        }
        free(Board);
        return 1;
    }
    x--;
    y--;

    bool result = DFS(Board, n, x, y, step);
    if (result) {
        printf("成功找到路径，路径如下：\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d", Board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("未找到路径。\n");
    }

    // 释放动态分配的内存
    for (int i = 0; i < n; i++) {
        free(Board[i]);
    }
    free(Board);
    return 0;
}    