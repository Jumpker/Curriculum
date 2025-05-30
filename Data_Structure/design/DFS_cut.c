#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义棋盘上的点结构
typedef struct {
    int x;
    int y;
} Point;

// 定义马的移动方向结构
typedef struct {
    int dx;
    int dy;
} Move;

// 计算从(x,y)出发的每个方向的下一步可走方向数
void calculateNextSteps(int **Board, int Size, Point current_pos, const Move knight_moves[8], int next_steps[8]) {
    for (int i = 0; i < 8; i++) {
        int nx = current_pos.x + knight_moves[i].dx;
        int ny = current_pos.y + knight_moves[i].dy;

        // 检查下一步是否在棋盘内且未被访问
        if (nx >= 0 && nx < Size && ny >= 0 && ny < Size && Board[nx][ny] == 0) {
            next_steps[i] = 0;
            // 计算从(nx,ny)出发的下一步可走方向数
            for (int j = 0; j < 8; j++) {
                int nnx = nx + knight_moves[j].dx;
                int nny = ny + knight_moves[j].dy;
                if (nnx >= 0 && nnx < Size && nny >= 0 && nny < Size && Board[nnx][nny] == 0) {
                    next_steps[i]++;
                }
            }
        } else {
            next_steps[i] = -1; // 标记为无效方向
        }
    }
}

// 根据Warnsdorff规则，按下一步可走方向数升序排序方向
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

// 深度优先搜索函数，用于寻找马的遍历路径
bool DFS(int **Board, int Size, Point current_pos, int step) {
    // 定义马的八个可能的移动方向
    Move knight_moves[8] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // 标记当前位置为已访问，并记录步数
    Board[current_pos.x][current_pos.y] = step;

    // 如果所有格子都被访问，则找到一个解
    if (step == Size * Size) {
        return true;
    }

    // 存储每个方向的下一步可走方向数
    int next_steps[8];
    calculateNextSteps(Board, Size, current_pos, knight_moves, next_steps);

    // 存储排序后的方向索引
    int indices[8];
    sortDirections(indices, next_steps);

    // 尝试按Warnsdorff规则排序后的方向进行递归
    for (int k = 0; k < 8; k++) {
        int i = indices[k];
        // 跳过无效或已访问的方向
        if (next_steps[i] == -1) {
            continue;
        }

        // 计算下一个位置
        Point next_pos = {current_pos.x + knight_moves[i].dx, current_pos.y + knight_moves[i].dy};

        // 递归调用DFS
        if (DFS(Board, Size, next_pos, step + 1)) {
            return true;
        }
    }

    // 如果当前路径无法找到解，则回溯，将当前位置标记为未访问
    Board[current_pos.x][current_pos.y] = 0;
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
    printf("请输入你的马的初始位置。\n注意：左上角格为(1, 1)，x正轴往右，y正轴往下，用空格隔开：\n");
    scanf("%d %d", &x, &y);
    // 将用户输入的1-indexed坐标转换为0-indexed
    x--; 
    y--;
    int temp = x;
    x = y;
    y = temp;
    if (x < 0 || x >= n || y < 0 || y >= n) {
        printf("初始位置超出棋盘范围！\n");
        return 1;
    }
    // 将用户输入的起始位置转换为Point结构体
    Point start_pos = {x, y};

    // 调用DFS函数开始寻找马的遍历路径
    bool result = DFS(Board, n, start_pos, 1);
    if (result) {
        printf("找到有解，路线如下：\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d\t", Board[i][j]);
            }
            printf("\n");
        }
    }else printf("无解！");
    for (int i = 0; i < n; i++) free(Board[i]);
    free(Board);
    return 0;
}