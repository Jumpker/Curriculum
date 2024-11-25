#include<stdio.h>
char str[10] = {'\0'};

void convert(char a[], int n){
    int i = 0;
    while(n != 0){
        a[i] = n%10 + '0';
        n = n/10;
        i++;
    }
}

void main(){
    int num;
    scanf("%d", &num);
    convert(str, num);
    puts(str);
}