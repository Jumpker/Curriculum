#include <stdio.h>
#include <stdlib.h>

void min_sort(int *array){
    int i, j, temp;
    if(array[0] > array[1]){
        temp = array[0];
        array[0] = array[1];
        array[1] = temp;

    }
}

void find_num(int *array, int arraySize){
    int a[2] = {0, 0};
    int i, j = 0;
    int b[1000001];
    for(i=0; i<arraySize; i++){
        b[array[i]]++;
    }
    for(i=0; i<1000001; i++){
        if(b[i] == 1){
            a[j] = i;
            j++;
        }
    }
    min_sort(a);
}

int main(){
    int array[6] = {1,2,1,3,2,5};
    int returnSize = 0;
    find_num(array, 6);
    printf("%d %d", array[0], array[1]);
    return 0;
}