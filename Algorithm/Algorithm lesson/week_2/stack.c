#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int val = stack[top];
    top--;
    return val;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}