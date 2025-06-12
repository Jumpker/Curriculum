#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
stack<char> symbol;
stack<int> state;
char sen[50];
char sym[12][6]={//符号表
   {'s','e','e','s','e','e'},
   {'e','s','e','e','e','a'},
   {'r','r','s','r','r','r'},
   {'r','r','r','r','r','r'},
   {'s','e','e','s','e','e'},
   {'r','r','r','r','r','r'},
   {'s','e','e','s','e','e'},
   {'s','e','e','s','e','e'},
   {'e','s','e','e','s','e'},
   {'r','r','s','r','r','r'},
   {'r','r','r','r','r','r'},
   {'r','r','r','r','r','r'}
};
char snum[12][6]={//数字表
{5,1,1,4,2,1},
{3,6,5,3,2,0},
{2,2,7,2,2,2},
{4,4,4,4,4,4},
{5,1,1,4,2,1},
{6,6,6,6,6,6},
{5,1,1,4,2,1},
{5,1,1,4,2,1},
{3,6,5,3,11,4},
{1,1,7,1,1,1},
{3,3,3,3,3,3},
{5,5,5,5,5,5}
};
int go2[12][3]={//goto表
{1,2,3},
{0,0,0},
{0,0,0},
{0,0,0},
{8,2,3},
{0,0,0},
{0,9,3},
{0,0,10},
{0,0,0},
{0,0,0},
{0,0,0},
{0,0,0}
};
void action(int i,char *&a,char &how,int &num,char &A,int &b)//action函数[i,a]
{
int j;
switch(*a)
{
case 'i':
   j=0;break;
case '+':
   j=1;break;
case '*':
   j=2;break;
case '(':
   j=3;break;
case ')':
   j=4;break;
case '#':
   j=5;break;
default:
   j=-1;break;
}
printf("%c\t\t",*a);
if(j!=-1)
{
   how=sym[i][j];
   num=snum[i][j];
   if(how=='r')
   {
    switch(num)
    {
    case 1:
     A='E',b=3;
     cout<<"reduce by E->E+T"<<endl;
     break;
    case 2:
     A='E',b=1;
     cout<<"reduce by E->T"<<endl;
     break;
    case 3:
     A='T',b=3;
     cout<<"reduce by T->T*F"<<endl;
     break;
    case 4:
     A='T',b=1;
     cout<<"reduce by T->F"<<endl;
     break;
    case 5:
     A='F',b=3;
     cout<<"reduce by F->(E)"<<endl;
     break;
    case 6:
     A='F',b=1;
     cout<<"reduce by F->id"<<endl;
     break;
    default:
     break;
    }
   }
}
}

int go(int t,char A)//goto[t,A]
{
switch(A)
{
case 'E':
   return go2[t][0];break;
case 'T':
   return go2[t][1];break;
case 'F':
   return go2[t][2];break;
}
}
void error(int i,int j,char *&a)//error处理函数
{
switch(j)
{
case 1://期望输入id或左括号,但是碰到+,*,或$,就假设已经输入id了,转到状态5
   cout<<"error:缺少运算对象id"<<endl;
   symbol.push('i');//必须有这个,如果假设输入id的话,符号栈里必须有....
   printf("i\t\t"); 
   state.push(5);
   printf("5\t\t"); 
   break;
case 2://从输入中删除右括号
   a++;
   cout<<"error:不配对的右括号"<<endl;
   break;
case 3://期望碰到+,但是输入id或左括号,假设已经输入算符+,转到状态6
   cout<<"error:缺少运算符"<<endl;
   symbol.push('+');
   printf("+\t\t"); 
   state.push(6);
   printf("6\t\t");
   break;
case 4://缺少右括号,假设已经输入右括号,转到状态11
   cout<<"error:缺少右括号"<<endl;
   symbol.push(')');
   printf(")\t\t");
   state.push(11);
   printf("11\t\t");
   break;
case 5:
   a++;
   cout<<"error:*号无效,应该输入+号!"<<endl;
case 6:
   a++;
}
}

int main()
{
int s;
char *a;
char how;
int num;
int b;
char A;
cout<<"请输入表达式(以i表示标识符,以#结束):"<<endl; 
while(1)
{
   cin>>sen;
   a=sen;
   state.push(0);//先输入0状态 
   printf("\t\t-------分析过程-------\n"); 
   printf("符号栈栈顶\t状态栈栈顶\t当前读入符号\t分析动作\n"); 
   printf(" \t\t0\t\t"); 
   while(*a!='\0')
   {
    b=0;num=0;how='\0';A='\0';
    s=state.top();
    action(s,a,how,num,A,b);
    if(how=='s')//移进
    {
     cout<<"Shift"<<endl;
     symbol.push(*a);
     printf("%c\t\t",*a);
     state.push(num);
     printf("%d\t\t",num);
     a++;
    }
    else if(how=='r')//规约
    {
     for(int i=0;i<b;i++)
     {
      if(!state.empty())
       state.pop();
      if(!symbol.empty())
       symbol.pop();
     }
     int t=state.top();
     symbol.push(A);
      printf("%c\t\t",A);
     state.push(go(t,A));
      printf("%d\t\t",go(t,A));
    }
    else if(how=='a')//接受
     break;
    else
    {
     error(s,num,a);//错误处理    
    }
   }
   cout<<"accept"<<endl;
}
return 0;
}
