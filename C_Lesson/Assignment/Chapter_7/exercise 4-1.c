#include<stdio.h>
void main(){
    int i, a[20], sum, count;
    sum = count = 0;
    for(i=0; i<20; i++)
        scanf("%d", &a[i]);
    for(i=0; i<20; i++)
        if(a[i] > 0){
            count++;
            sum += a[i];
        }
    printf("sum = %d, count = %d\n", sum, count);
}