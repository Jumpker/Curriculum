#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef char ElemType;
typedef struct
{	ElemType data[MaxSize];
	int top;							//栈顶指针 
} SqStack;								//声明顺序栈类型

void InitStack(SqStack *&s)				//初始化顺序栈
{	s = (SqStack * )malloc(sizeof(SqStack));
	s -> top = -1;
 } 
 
void DestroyStack(SqStack *&s)			//销毁顺序栈
{
	free(s);
 }
 
bool StackEmpty(SqStack *s)				//判断栈空否
{
	return(s->top==-1);
 } 
 
bool Push(SqStack *&s,ElemType e)		//进栈
{	if (s->top == MaxSize - 1) 			//栈满, 上溢
		return false;
	s -> top++;
	s -> data[s->top]=e;
	return true; 
 } 
 
bool Pop(SqStack *&s,ElemType &e)		//出栈
{	if (s->top == -1)					//栈为空, 下溢
		return false;
	e = s->data[s->top];	
	s -> top--; 
	return true;
 } 
 
bool GetTop(SqStack *s,ElemType &e)		//取栈顶元素
{	if (s->top == -1)					//栈空, 下溢 
		return false;
	e = s->data[s->top];
	return true;
 } 
