#include<stdio.h>

void main(){
    int a[5], num, count=0, i;
    printf("请输入一个不多于5位的数字: ");
    scanf("%d", &num);
    while(num != 0){
        a[count] = num % 10;
        num /= 10;
        count++;
    }
    printf("%d\n", count);
    for(i=count-1; i>=0; i--)
        printf("%d ", a[i]);
}