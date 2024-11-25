#include<stdio.h>

void XuanZe(int a[]){
    int t, i, j=1;
    for(i=0; i<9; i++){
        for(j=i+1; j<10; j++){  
            if(a[i] > a[j]){
                t = a[i]; a[i] = a[j]; a[j] = t;        //交换a[i]和a[j]
            }
        }
    }
    for(i=0; i<10; i++)
        printf("%d ", a[i]);
}

void main(){
    int a[10];
    printf("请依次输入你要排序的10个整数(升序): ");
    for(int i = 0; i < 10; i++){
        scanf("%d", &a[i]);
    }
    printf("排序后的结果为: ");
    XuanZe(a);
}