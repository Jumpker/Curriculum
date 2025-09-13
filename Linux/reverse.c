#include <stdio.h>
#include <string.h>

void reverse(char arr[]){
    int n = strlen(arr);
    int temp;
    for(int i=0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

void main(){
    char arr[104];
    scanf("%s", arr);
    reverse(arr);
    printf("%s", arr);
}