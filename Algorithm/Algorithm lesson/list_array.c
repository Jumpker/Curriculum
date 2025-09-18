#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    int size;
    int index;
    int *array;
};

void add(struct list *l, int val){
    if(l->index == l->size-1){
        printf("List is full\n");
    }
    else{
        l->index++;
        l->array[l->index] = val;
    }
    return;
}