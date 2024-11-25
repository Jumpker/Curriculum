#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
//-------非递归算法--------------------------------- 
typedef struct
{	int n;								//盘片个数 
	char x,y,z;							//3个塔座 
	bool flag;							//可直接移动盘片时为true, 否则为false 
}ElemType;								//顺序栈中元素的类型

typedef struct 
{	ElemType data[MaxSize];				//存放元素 
	int top;							//栈顶指针 
} StackType;								//声明顺序栈类型

//----求解Hanoi问题对应顺序栈的基本运算算法----------
 
void InitStack(StackType *&s)				//初始化顺序栈
{	s = (StackType * )malloc(sizeof(StackType));
	s -> top = -1;
 } 
 
void DestroyStack(StackType *&s)			//销毁顺序栈
{
	free(s);
 }
 
bool StackEmpty(StackType *s)				//判断栈空否
{
	return(s->top==-1);
 } 
 
bool Push(StackType *&s,ElemType e)		//进栈
{	if (s->top == MaxSize - 1) 			//栈满, 上溢
		return false;
	s -> top++;
	s -> data[s->top]=e;
	return true; 
 } 
 
bool Pop(StackType *&s,ElemType &e)		//出栈
{	if (s->top == -1)					//栈为空, 下溢
		return false;
	e = s->data[s->top];	
	s -> top--; 
	return true;
 } 



void Hanoi2(int n, char x, char y, char z)
{	StackType * st;						//定义顺序栈指针
	ElemType e, e1, e2, e3;
	if (n<=0) return;					//参数错误时直接返回
	InitStack(st);						//初始化栈
	e.n=n; e.x=x; e.y=y; e.z=z; e.flag=false;
	Push(st,e);							//元素e进栈
	while(!StackEmpty(st))				//栈不空循环
	{	Pop(st,e);						//出栈元素e
		if(e.flag==false)				//当不能直接移动盘片时 
		{	e1.n=e.n-1; e1.x=e.y; e1.y=e.x; e1.z=e.z;
			if(e1.n == 1)				//只有一个盘片时可直接移动
				e1.flag = true;
			else						//有一个以上盘片时不能直接移动
				e1.flag = false;
			Push(st, e1);				//处理Hanoi(n-1,y,x,z步骤
			e2.n=e.n; e2.x=e.x; e2.y=e.y; e2.z=e.z; e2.flag=true;
			Push(st, e2);				//处理move(n,x,z)步骤
			e3.n=e.n-1; e3.x=e.x; e3.y=e.z; e3.z=e.y;
			if (e3.n == 1)				//只有一个盘片时可直接移动
				e3.flag = true;
			else						//有一个以上盘片时不能直接移动
				e3.flag = false;
			Push(st,e3);				//处理Hanoi(n-1,x,z,y)步骤 
		}
	 	else							//当可以直接移动时 
	 		printf("\t将第%d个盘片从%c移动到%c\n",e.n,e.x,e.z);
	 } 
 	DestroyStack(st);					//销毁栈 
 } 
 //-----------------------------------------------------
 int main(){
 	int n = 3;
 	printf("非递归算法: %d个盘片移动过程:\n",n);
 	Hanoi2(n,'X','Y','Z');
 	return 1;
 } 
