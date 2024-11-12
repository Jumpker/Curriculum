#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef char ElemType;
typedef struct
{	ElemType data[MaxSize];
	int top;							//Õ»¶¥Ö¸Õë 
} SqStack;								//ÉùÃ÷Ë³ÐòÕ»ÀàÐÍ

void InitStack(SqStack *&s)				//³õÊ¼»¯Ë³ÐòÕ»
{	s = (SqStack * )malloc(sizeof(SqStack));
	s -> top = -1;
 } 
 
void DestroyStack(SqStack *&s)			//Ïú»ÙË³ÐòÕ»
{
	free(s);
 }
 
bool StackEmpty(SqStack *s)				//ÅÐ¶ÏÕ»¿Õ·ñ
{
	return(s->top==-1);
 } 
 
bool Push(SqStack *&s,ElemType e)		//½øÕ»
{	if (s->top == MaxSize - 1) 			//Õ»Âú, ÉÏÒç
		return false;
	s -> top++;
	s -> data[s->top]=e;
	return true; 
 } 
 
bool Pop(SqStack *&s,ElemType &e)		//³öÕ»
{	if (s->top == -1)					//Õ»Îª¿Õ, ÏÂÒç
		return false;
	e = s->data[s->top];	
	s -> top--; 
	return true;
 } 
 
bool GetTop(SqStack *s,ElemType &e)		//È¡Õ»¶¥ÔªËØ
{	if (s->top == -1)					//Õ»¿Õ, ÏÂÒç 
		return false;
	e = s->data[s->top];
	return true;
 } 
