#include<stdio.h>
void main(){
	int i, score;
	printf("输入一个-1程序结束。\n\n输入一个分数后回车: ");
	scanf("%d",&score); 
	while(score >= 0){									//循环结构
		switch (score / 10){							//循环嵌套选择结构 
		case 10:
		case 9: printf("%d: A\n", score);break;
		case 8:
		case 7: printf("%d: B\n", score);break;
		case 6: printf("%d: C\n", score);break;
		default: printf("%d: D\n", score);
		} 
	printf("输入下一个分数后回车: ");
	scanf("%d",&score);									//输入下一个学生的成绩 
	}
}
