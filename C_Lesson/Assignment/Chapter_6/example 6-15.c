#include<windows.h>
#include<stdio.h>

int divisor(int a, int b){
    int r;
    while ((r = a%b) != 0)
    {a=b; b=r;}
    return b;
}

int multiple(int a, int b){
    printf("最大公约数: %d\n", divisor(a,b));
    return a*b/divisor(a,b);
}

void main(){
    int a, b, c;
    printf("输入a: ");
    scanf("%d", &a);
    printf("输入b: ");
    scanf("%d", &b);
    c = multiple(a,b);
    printf("最小公倍数: %d\n", c);
    system("pause");
}