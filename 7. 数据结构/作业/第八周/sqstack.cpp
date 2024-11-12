#include <stdlib.h>  
#include <string.h>  
#include <stdbool.h>  
  
#define MAX_SIZE 100  // 栈的最大容量  
  
// 顺序栈结构体  
typedef struct {  
    char data[MAX_SIZE];  
    int top;  
} Stack;  
  
// 初始化栈  
void initStack(Stack *s) {  
    s->top = -1;  
}  
  
// 判断栈是否为空  
bool isEmpty(Stack *s) {  
    return s->top == -1;  
}  
  
// 进栈  
bool push(Stack *s, char c) {  
    if (s->top >= MAX_SIZE - 1) {  
        // 栈满，进栈失败  
        return false;  
    }  
    s->data[++(s->top)] = c;  
    return true;  
}  

// 出栈  
char pop(Stack *s) {  
    if (isEmpty(s)) {  
        exit(EXIT_FAILURE); 		//栈为空, 下溢 
    }  
    return s->data[(s->top)--];  
}  

  
