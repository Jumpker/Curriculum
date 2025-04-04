#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef char ElemType;
typedef struct node{
	ElemType data;							//数据元素
	struct node * lchild;					//指向左孩子节点 
	struct node * rchild; 					//指向右孩子节点 
}BTNode;									//声明二叉链节点类型 
	
void CreateBTree(BTNode * &b, char * str){	//创建二叉树
	BTNode * St[MaxSize], * p;
	int top = -1, k, j=0; char ch;
	b = NULL;								//建立的二叉树初始时为空
	ch = str[j];
	while(ch != '\0'){						//str未扫描完时循环
		switch(ch){
			case '(':top++; St[top]=p; k=1; break;			//开始处理左子树
			case ')':top--; break;							//子树处理完毕
			case ',':k=2; break;							//开始处理右子树
			default: p = (BTNode * )malloc(sizeof(BTNode));
				p->data = ch; p->lchild = p->rchild = NULL;
				if(b == NULL)								//若b为空, p置为二叉树的根节点
					b = p;
				else{										//已建立二叉树根节点
					switch(k){
						case 1:St[top]->lchild = p; break;
						case 2:St[top]->rchild = p; break;
					} 
				} 
		} 
		j++; ch = str[j];
	}						 
}

void DestoryBTree(BTNode * &b){				//销毁二叉树
	if(b != NULL){
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		free(b);
	} 
}
	
BTNode * FindNode(BTNode * b, ElemType x){	//查找值为x的节点 
	BTNode *p;
	if(b == NULL)
		return NULL;
	else if(b->data == x)
		return b;
	else{
		p = FindNode(b->lchild, x);
		if(p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	} 
}

BTNode * LchildNode(BTNode * p){				//返回p结点的左孩子结点指针
	return p->lchild; 
}

BTNode * RchildNode(BTNode * p){				//返回p结点的右孩子结点指针
	return p->rchild; 
}

int BTHeight(BTNode * b){						//求二叉树的高度
	int lchildh, rchildh;
	if(b == NULL) return 0;						//空树的高度为0
	else{
		lchildh = BTHeight(b->lchild);			//求左子树的高度为lchildh 
		rchildh = BTHeight(b->rchild);			//求右子树的高度为rchildh
		return (lchildh > rchildh)? (lchildh+1):(rchildh+1);
	} 
}

void DispBTree(BTNode * b){						//以括号表示法输出二叉树
	if(b != NULL){
		printf("%c",b->data);
		if(b->lchild != NULL || b->rchild != NULL){
			printf("(");						//有孩子结点时才输出(
			DispBTree(b->lchild);				//递归处理左子树
			if(b->rchild != NULL) printf(",");	//有右孩子结点时才输出,
			DispBTree(b->rchild);				//递归处理右子树
			printf(")");						//有孩子结点时才输出(
		}
	} 
}
