#include "btree.cpp"								//�����������Ļ��������㷨 
#define MaxWidth 40

BTNode *CreateBT1(char *pre, char *in, int n){		//�����������������й�������� 
	BTNode *b;
	char *p; int k;
	if (n<=0) return NULL;
	b = (BTNode *)malloc(sizeof(BTNode));			//�������������b
	b->data = *pre;
	for (p=in; p<in+n; p++)							//�������������ҵ���*pre�ַ���λ��k
		if(*p == *pre)								//preָ����ڵ�
			break;									//��in���ҵ����˳�ѭ��
	k = p - in;										//ȷ�����ڵ���in�е�λ��
	b->lchild = CreateBT1(pre+1, in, k);			//�ݹ鹹�������� 
	b->rchild = CreateBT1(pre+k+1, p+1, n-k-1);		//�ݹ鹹��������
	return b;
}

BTNode *CreateBT2(char *post, char *in, int n){		//������ͺ���������й�������� 
	BTNode *b; char r, *p; int k;
	if(n<=0) return NULL;
	r = *(post+n-1);								//ȡ���ڵ�ֵ
	b = (BTNode *)malloc(sizeof(BTNode));			//�������������*b
	b->data = r;
	for(p=in; p<in+n; p++)							//��in�в��Ҹ��ڵ�
		if(*p == r) break;
	k = p-in;										//kΪ���ڵ���in�е��±�
	b->lchild = CreateBT2(post, in, k);				//�ݹ鹹�������� 
	b->rchild = CreateBT2(post+k, p+1, n-k-1);		//�ݹ鹹��������
	return b;
}

void DispBTree1(BTNode *b){							//�԰����ʾ�����һ�ö�����
	BTNode *St[MaxSize], *p;
	int level[MaxSize][2], top=-1, n, i, width=4;
	char type;										//������Һ��ӱ��
	if (b != NULL){
		top++; St[top]=b;							//������ջ
		level[top][0] = width;
		level[top][1] = 2;							//2��ʾ�Ǹ�
		while (top>-1){								//ջ����ѭ�� 
			p = St[top];							//ȡջ�����, ��������ʾ�ýڵ�ֵ
			n = level[top][0];						//ȡ��������ʾ����, ����ߵĿո����
			switch(level[top][1]){
				case 0: type = 'L'; break;			//����֮�����(L)
				case 1: type = 'R'; break; 			//�ҽ��֮�����(R) 
				case 2: type = 'B'; break; 			//�����֮�����(B) 
			}
			for(i=1; i<=n; i++)						//����nΪ��ʾ����, �ַ����Ҷ�����ʾ
			 	printf(" ");
			printf("%c(%c)", p->data, type);
			for(i=n+1; i<=MaxWidth; i+=2)
				printf("--");
			printf("\n");
			top--;									//��ջ
			if(p->rchild != NULL){
				top++;
				St[top] = p->rchild;				//�Һ��ӽ�ջ
				level[top][0] = n+width;			//��ʾ������width
				level[top][1] = 0;					//0��ʾ�������� 
			} 
		}
	} 
}

int main(){
	BTNode *b;
	ElemType pre[]  = "ABDEHJKLMNCFGI";
	ElemType in[]   = "DBJHLKMNEAFCGI";
	ElemType post[] = "DJLNMKHEBFIGCA";
	int n = 14;										//�������й���14�����
	b = CreateBT1(pre, in, n);
	printf("��������: %s\n", pre);
	printf("��������: %s\n", in);
	printf("����һ�ö�����b: \n");
	printf("  ���ű�ʾ��: "); DispBTree(b); printf("\n");
	printf("  �����ʾ��: \n"); DispBTree1(b); printf("\n\n");
	printf("��������: %s\n", in);
	printf("��������: %s\n", post);
	b = CreateBT2(post, in, n);
	printf("����һ�ö�����b: \n");
	printf("  ���ű�ʾ��: "); DispBTree(b); printf("\n");
	printf("  �����ʾ��: \n"); DispBTree1(b); printf("\n");
	DestoryBTree(b);
	return 1;
} 
