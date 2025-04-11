#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 计算从(x,y)出发的每个方向的下一步可走方向数
void calculateNextSteps(int **Board, int Size, int x, int y, const int mv[8][2], int next_steps[8]) {
    for (int i = 0; i < 8; i++) {
        int nx = x + mv[i][0], ny = y + mv[i][1];
        if (nx >= 0 && nx < Size && ny >= 0 && ny < Size && Board[nx][ny] == 0) {
            next_steps[i] = 0;
            // 计算(nx,ny)的下一步可走方向数
            for (int j = 0; j < 8; j++) {
                int nnx = nx + mv[j][0], nny = ny + mv[j][1];
                if (nnx >= 0 && nnx < Size && nny >= 0 && nny < Size && Board[nnx][nny] == 0) {
                    next_steps[i]++;
                }
            }
        } else {
            next_steps[i] = -1; // 标记无效方向
        }
    }
}

// 按next_steps升序排序方向（Warnsdorff规则）
void sortDirections(int indices[8], const int next_steps[8]) {
    // 初始化方向索引
    for (int i = 0; i < 8; i++) indices[i] = i;
    // 简单冒泡排序（按next_steps升序）
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (next_steps[indices[i]] > next_steps[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
}

bool DFS(int **Board, int Size, int x, int y, int step) {
    int mv[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    
    if (step == Size * Size) {
        Board[x][y] = step;
        return true;
    }
    Board[x][y] = step;

    // 计算每个方向的下一步可走方向数
    int next_steps[8];
    calculateNextSteps(Board, Size, x, y, mv, next_steps);

    // 按next_steps升序排序方向
    int indices[8];
    sortDirections(indices, next_steps);

    // 按排序后的方向递归
    for (int k = 0; k < 8; k++) {
        int i = indices[k];
        if (next_steps[i] == -1) continue; // 跳过无效方向
        int nx = x + mv[i][0], ny = y + mv[i][1];
        if (DFS(Board, Size, nx, ny, step + 1)) return true;
    }

    Board[x][y] = 0; // 回溯
    return false;
}

int main() {
    int n;
    printf("请输入棋盘大小：");
    scanf("%d", &n);
    
    int **Board = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        Board[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) Board[i][j] = 0;
    }

    int x, y;
    printf("请输入你的马的初始位置，左上角格为(1, 1)，用空格隔开：");
    scanf("%d %d", &x, &y);
    if (x < 1 || x > n || y < 1 || y > n) {
        printf("初始位置超出棋盘范围！\n");
        return 1;
    }
    x--; y--;

    bool result = DFS(Board, n, x, y, 1);
    printf("%d\n", result ? 1 : 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", Board[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) free(Board[i]);
    free(Board);
    return 0;
}