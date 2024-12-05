#include<stdio.h>
#include<malloc.h>
#define MAXL 100                                            //顺序表的最大长度

typedef int KeyType;                                        //定义关键字类型为int
typedef char InfoType;
typedef struct{
    KeyType key;                                            //关键字项
    InfoType data;                                          //其它数据项, 类型为InfoType
}RecType;                                                   //声明查找顺序表元素类型

void CreateList(RecType R[], KeyType keys[], int n){        //创建顺序表
    for(int i=0; i<n; i++)
        R[i].key = keys[i];
}

void DispList(RecType R[], int n){                          //输出顺序表
    for(int i=0; i<n; i++)
        printf("%d ", R[i].key);
    printf("\n");
}