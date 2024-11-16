#include "btree.cpp"								//包含二叉树的基本运算算法 
#define MaxWidth 40

BTNode *CreateBT1(char *pre, char *in, int n){		//由先序和中序遍历序列构造二叉树 
	BTNode *b;
	char *p; int k;
	if (n<=0) return NULL;
	b = (BTNode *)malloc(sizeof(BTNode));			//创建二叉树结点b
	b->data = *pre;
	for (p=in; p<in+n; p++)							//在中序序列中找等于*pre字符的位置k
		if(*p == *pre)								//pre指向根节点
			break;									//在in中找到后退出循环
	k = p - in;										//确定根节点在in中的位置
	b->lchild = CreateBT1(pre+1, in, k);			//递归构造左子树 
	b->rchild = CreateBT1(pre+k+1, p+1, n-k-1);		//递归构造右子树
	return b;
}

BTNode *CreateBT2(char *post, char *in, int n){		//由中序和后序遍历序列构造二叉树 
	BTNode *b; char r, *p; int k;
	if(n<=0) return NULL;
	r = *(post+n-1);								//取根节点值
	b = (BTNode *)malloc(sizeof(BTNode));			//创建二叉树结点*b
	b->data = r;
	for(p=in; p<in+n; p++)							//在in中查找根节点
		if(*p == r) break;
	k = p-in;										//k为根节点在in中的下标
	b->lchild = CreateBT2(post, in, k);				//递归构造左子树 
	b->rchild = CreateBT2(post+k, p+1, n-k-1);		//递归构造右子树
	return b;
}

void DispBTree1(BTNode *b){							//以凹入表示法输出一棵二叉树
	BTNode *St[MaxSize], *p;
	int level[MaxSize][2], top=-1, n, i, width=4;
	char type;										//存放左右孩子标记
	if (b != NULL){
		top++; St[top]=b;							//根结点进栈
		level[top][0] = width;
		level[top][1] = 2;							//2表示是根
		while (top>-1){								//栈不空循环 
			p = St[top];							//取栈顶结点, 并凹入显示该节点值
			n = level[top][0];						//取根结点的显示场宽, 即左边的空格个数
			switch(level[top][1]){
				case 0: type = 'L'; break;			//左结点之后输出(L)
				case 1: type = 'R'; break; 			//右结点之后输出(R) 
				case 2: type = 'B'; break; 			//根结点之后输出(B) 
			}
			for(i=1; i<=n; i++)						//其中n为显示场宽, 字符以右对其显示
			 	printf(" ");
			printf("%c(%c)", p->data, type);
			for(i=n+1; i<=MaxWidth; i+=2)
				printf("--");
			printf("\n");
			top--;									//退栈
			if(p->rchild != NULL){
				top++;
				St[top] = p->rchild;				//右孩子进栈
				level[top][0] = n+width;			//显示场宽增width
				level[top][1] = 0;					//0表示是左子树 
			} 
		}
	} 
}

int main(){
	BTNode *b;
	ElemType pre[]  = "ABDEHJKLMNCFGI";
	ElemType in[]   = "DBJHLKMNEAFCGI";
	ElemType post[] = "DJLNMKHEBFIGCA";
	int n = 14;										//二叉树中共有14个结点
	b = CreateBT1(pre, in, n);
	printf("先序序列: %s\n", pre);
	printf("中序序列: %s\n", in);
	printf("构造一棵二叉树b: \n");
	printf("  括号表示法: "); DispBTree(b); printf("\n");
	printf("  凹入表示法: \n"); DispBTree1(b); printf("\n\n");
	printf("中序序列: %s\n", in);
	printf("后序序列: %s\n", post);
	b = CreateBT2(post, in, n);
	printf("构造一棵二叉树b: \n");
	printf("  括号表示法: "); DispBTree(b); printf("\n");
	printf("  凹入表示法: \n"); DispBTree1(b); printf("\n");
	DestoryBTree(b);
	return 1;
} 
