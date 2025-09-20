#include <stdio.h>

int min(int n, int arr[]){
    int min = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

void main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", min(n, arr));
}