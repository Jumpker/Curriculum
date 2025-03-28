#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool DFS(int **Board,int Size, int x, int y, int step){
    int mv[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};     //马走日
    if(step==Size*Size) return true  ;                                          //成功周游
    Board[x][y]=step++;                                                           //设置该位置走过了
    int nx,ny;
    for(int i=0;i<8;i++){                                                       //遍历八个方向
        nx = x + mv[i][0];
        ny = y + mv[i][1];
        if(nx>=0 && nx<Size && ny>=0 && ny<Size && Board[nx][ny]==0){                  //不能飞出棋盘, 且下的位置没走过                                                   
            if (DFS(Board, Size, nx, ny, step)) return true;                  //递归判断下面的路能不能走通
        }
    }
    Board[x][y]=0;                                                     //如果下面的路不通，则该位置没走过  
    return false;                                                               //如果所有路都走不通，则返回false
}
int main(){
    int n;                             //棋盘大小, n*n的棋盘输入一个n值就行
    printf("请输入棋盘大小：");
    scanf("%d",&n);                            
    int **Board = (int **)malloc(sizeof(int *)*n);
    for (int i = 0; i < n; i++) {
        Board[i] = (int *)malloc(n * sizeof(int));
    }
    int x, y, step=1;
    for(int i=0;i<n;i++){               //初始化棋盘
        for(int j=0;j<n;j++){
            Board[i][j]=0;
        }
    }
    printf("请输入你的马的初始位置，左上角格为(1, 1)，用空格隔开：");
    scanf("%d %d",&x,&y);
    if (x < 0 || x > n-1 || y < 0 || y > n-1){
        printf("初始位置超出棋盘范围！\n");
        return 1;
    }
    x--;y--;
    bool result = DFS(Board, n, x, y, step);
    printf("%d\n", result ? 1 : 0);            // 输出结果，将bool转换为整数

    // 释放动态分配的内存
    for (int i = 0; i < n; i++) {
        free(Board[i]);
    }
    free(Board);
}