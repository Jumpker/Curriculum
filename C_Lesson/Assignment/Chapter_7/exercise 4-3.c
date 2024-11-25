#include<stdio.h>

void d(char s[], int i, int n){
    int j, k, length=0;                                 //length用于计算字符串的长度
    while (s[length])   length++;
    i--; j=i;
    if(i < length){
        k = i + n;
        if(i+n <= length)
            while (k < length) s[j++] = s[k++];
            s[j] = '\0';
    }
}

void main(){
    char a[20];
    scanf("%s", a);
    d(a, 2, 2);
    puts (a);
}