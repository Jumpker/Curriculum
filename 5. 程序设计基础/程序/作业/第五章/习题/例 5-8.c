#include<stdio.h>
void main(){
	int i, score;
	printf("����һ��-1���������\n\n����һ��������س�: ");
	scanf("%d",&score); 
	while(score >= 0){									//ѭ���ṹ
		switch (score / 10){							//ѭ��Ƕ��ѡ��ṹ 
		case 10:
		case 9: printf("%d: A\n", score);break;
		case 8:
		case 7: printf("%d: B\n", score);break;
		case 6: printf("%d: C\n", score);break;
		default: printf("%d: D\n", score);
		} 
	printf("������һ��������س�: ");
	scanf("%d",&score);									//������һ��ѧ���ĳɼ� 
	}
}
