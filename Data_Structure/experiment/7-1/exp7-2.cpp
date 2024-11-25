#include"btree.cpp"

void PreOrder(BTNode *b){								//��������ĵݹ��㷨
	if(b != NULL){
		printf("%c ",b->data);							//���ʸ��ڵ�
		PreOrder(b->lchild);							//�ݹ����������
		PreOrder(b->rchild);							//�ݹ����������
	} 
}

void PreOrder1(BTNode *b){								//����ǵݹ�����㷨
	BTNode * St[MaxSize], *p;
	int top = -1;
	if(b != NULL){
		top++;											//���ڵ��ջ
		St[top] = b;
		while(top>-1){ 								//ջ��Ϊ��ʱ����ѭ�� 
			p= St[top];									//t��ջ�����ʸý��
			top--; 
			printf("%c ", p->data);
			if(p->rchild != NULL){						//���Һ���, �����ջ
				top++;
				St[top] = p->rchild; 
			}
			if(p->lchild != NULL){						//������, �����ջ
				top++;
				St[top] = p->lchild; 
			}
		}
		printf("\n");
	}
}

void InOrder(BTNode *b){								//��������ĵݹ��㷨 
	if(b != NULL){
		InOrder(b->lchild);								//�ݹ����������
		printf("%c ",b->data);							//���ʸ��ڵ�
		InOrder(b->rchild);								//�ݹ����������
	} 
}

void InOrder1(BTNode *b){								//����ǵݹ�����㷨
	BTNode * St[MaxSize], *p;
	int top = -1;
	if(b != NULL){
		p = b;
		while(top>-1 || p!=NULL){
			while(top != NULL){							//ɨ����p���������½�㲢��ջ 
				top++;
				St[top] = p;
				p = p->lchild; 
			}
			if(top > -1){
				p = St[top];							//��ջ���p������
				top--;
				printf("%c ",p->data);
				p = p->rchild; 
			}
		}
		printf("\n");
	}
}

void PostOrder(BTNode *b){								//��������ĵݹ��㷨 
	if(b != NULL){
		PostOrder(b->lchild);							//�ݹ����������
		PostOrder(b->rchild);							//�ݹ����������
		printf("%c ",b->data);							//���ʸ��ڵ�
	} 
}

void PostOrder1(BTNode *b){								//����ǵݹ�����㷨
	BTNode * St[MaxSize];
	BTNode *p;
	int top = -1;
	bool flag;
	if(b != NULL){
		do{
			while(b != NULL){							//��b�����������½���ջ
				top++;
				St[top] = b;
				b = b->lchild; 
			}
			p = NULL;									//pָ��ǰ����ǰһ���ѷ��ʵĽ��
			flag = true;								//flagΪ���ʾ���ڴ���ջ����� 
			while(top!=-1 && flag){
				b = St[top];								//ȡ����ǰ��ջ��Ԫ��
				if(b->rchild == p){							//�����������ڻ��ѱ�����, ����֮ 
					printf("%c ", b->data);					//����b���
					top--;
					p = b;									//pָ�򱻷��ʵĽ�� 
				}
				else{
					b = b->rchild;							//bָ��������
					flag = false;							//��ʾ��ǰ���Ǵ���ջ����� 
				}
			}
		}while(top != -1); 
		printf("\n");
	}
}

void TravLevel(BTNode * b){									//��α��� 
	BTNode * Qu[MaxSize];									//���廷�ζ���
	int front, rear;										//������׺Ͷ�βָ��
	front = rear = 0;										//�ö���Ϊ�ն�
	if(b != NULL) printf("%c ",b->data);
	rear++;													//���ڵ����
	Qu[rear] = b;
	while(rear != front){									//���в�Ϊ�� 
		front = (front + 1) % MaxSize;
		b = Qu[front];										//���ӽ��b
		if(b->lchild != NULL){								//�������, ������ 
			printf("%c ",b->lchild->data);
			rear = (rear+1) % MaxSize;
			Qu[rear] = b->lchild; 
		}
		if(b->rchild != NULL){								//����Һ���, ������
			printf("%c ",b->rchild->data);
			rear = (rear+1) % MaxSize;
			Qu[rear] = b->rchild; 
		}
	}
	printf("\n");
}

int main(){
	BTNode * b;
	CreateBTree(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("������b:"); DispBTree(b); printf("\n");
	printf("��α�������: \n");
	TravLevel(b);
	printf("�����������: \n");
	printf("    �ݹ��㷨: ");PreOrder(b); printf("\n");
	printf("  �ǵݹ��㷨: ");PreOrder1(b);
	printf("�����������: \n");
	printf("    �ݹ��㷨: ");InOrder(b); printf("\n");
	printf("  �ǵݹ��㷨: ");InOrder1(b);
	printf("�����������: \n");
	printf("    �ݹ��㷨: ");PostOrder(b); printf("\n");
	printf("  �ǵݹ��㷨: ");PostOrder1(b);
	DestoryBTree(b);
	return 1;
}
