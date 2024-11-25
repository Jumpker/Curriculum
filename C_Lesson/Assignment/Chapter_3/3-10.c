#include"stdio.h"
#include<windows.h>

void main(){
	char ch;
	printf("Input a lowercase letter: ");
	ch = getchar();								//输入字母存入ch 
	printf("%4c%4c%4c\n",ch-1,ch,ch+1);			//输出ch及前后的字母
	//每个数据分别以"%4d %4o"两种格式输出
	printf("%4d %4o,%4d %4o,%4d %4o,\n\n",ch-1,ch-1,ch,ch,ch+1,ch+1);
	ch = ch - 32;								//将小写字母转换为对应大写字母
	printf("%4c %4c %4c\n",ch-1,ch,ch+1);		
	//ch转换成大写字母后, 重复前面的输出语句 
	printf("%4d %4o,%4d %4o,%4d %4o,\n\n",ch-1,ch-1,ch,ch,ch+1,ch+1);
	system("pause");
}
