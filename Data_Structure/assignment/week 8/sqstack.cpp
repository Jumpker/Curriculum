#include <stdlib.h>  
#include <string.h>  
#include <stdbool.h>  
  
#define MAX_SIZE 100  // ջ���������  
  
// ˳��ջ�ṹ��  
typedef struct {  
    char data[MAX_SIZE];  
    int top;  
} Stack;  
  
// ��ʼ��ջ  
void initStack(Stack *s) {  
    s->top = -1;  
}  
  
// �ж�ջ�Ƿ�Ϊ��  
bool isEmpty(Stack *s) {  
    return s->top == -1;  
}  
  
// ��ջ  
bool push(Stack *s, char c) {  
    if (s->top >= MAX_SIZE - 1) {  
        // ջ������ջʧ��  
        return false;  
    }  
    s->data[++(s->top)] = c;  
    return true;  
}  

// ��ջ  
char pop(Stack *s) {  
    if (isEmpty(s)) {  
        exit(EXIT_FAILURE); 		//ջΪ��, ���� 
    }  
    return s->data[(s->top)--];  
}  

  
