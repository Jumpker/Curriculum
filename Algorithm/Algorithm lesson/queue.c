#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int size;
    int first;
    int last;
    int *array;
};

void enqueue(struct queue *q, int val){
    if(q->last == q->size-1){
        printf("Queue is full\n");
    }
    else{
        q->last++;
        q->array[q->last] = val;
    }
    return;
}

int dequeue(struct queue *q){
    int a = -1;
    if(q->first == q->last){
        printf("Queue is empty\n");
    }
    else{
        q->first++;
        a = q->array[q->first];
    }
    return a;
}

int front(struct queue *q){
    return q->array[q->first+1];
}

void main(){
    struct queue q;
    q.size = 100;
    q.first = q.last = -1;
    q.array = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", front(&q));
}