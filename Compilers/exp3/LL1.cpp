#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include <windows.h> // For SetConsoleOutputCP
#include <io.h>      // For _setmode
#include <fcntl.h>   // For _O_U8TEXT
using namespace std;
string Production[10]={"E->TG","G->+TG","G->-TG","G->ε","T->FS","S->*FS","S->/FS","S->ε","F->(E)","F->i"};//产生式集合
char termina[8]={'+','-','*','/','(',')','i','#'};//终结符集合
char nontermina[5]={'E','T','G','F','S'};//非终结符集合
int count=0;//记录当前进行处理的输入字符串字符位置
int line=0;//记录处理的步骤数
string stacktd="#E";//记录栈中内容
stack <char> Stack;//创建一个栈
char ch,ch1;//ch记录栈顶字符，ch1记录当前进行处理的输入字符串字符

int Istermina(char c){//判断其是否为终结符
	for(int i=0;i<8;i++){
    if(termina[i]==c)
		return 1;
	}
	return 0;
}
int Isnontermina(char c){//判断其是否为非终结符
	for(int i=0;i<5;i++){
    if(nontermina[i]==c)
		return 1;
	}
	return 0;
}
void OutputString(string s){//输出未处理的字符串
	for(int i=count;i<s.size();i++)
		cout<<s.at(i);
}
void Analyse(string s){//分析过程
    s=s+"#";
	Stack.push('#');//初始化
    Stack.push('E');
	cout<<line<<"\t"<<stacktd<<"\t";
    OutputString(s);
    cout<<"\t\t"<<"\t\t"<<"初始化"<<endl;
	line++;
	while(count<s.size()){//循环条件，输入串是否被处理完全

    ch=Stack.top();
	ch1=s.at(count);

	if(Istermina(ch)){
		if(ch==ch1&&ch!='#'){
         stacktd.erase(stacktd.length()-1);//删除stacktd字符串的尾字母
		 Stack.pop();
	     count++;
		 cout<<line<<"\t"<<stacktd<<"\t";
		 OutputString(s);
		 cout<<"\t\t"<<"\t\t"<<"GETNEXT("<<ch<<")"<<endl;

		}
		else if(ch='#'){
			cout<<"acc"<<"\t分析成功"<<endl;//表示分析完成，输入串为该文法的正确句型
			count=s.size();
		}
		else{
        cout<<"\tError"<<endl;//表示输入串为该文法的非法句型
		count=s.size();//使循环结束

		}
	}
	else switch(ch){//switch语句，具体分析非终结符面对输入串的具体执行情况
               case'E':{if(ch1=='('||ch1=='i'){
				           stacktd.erase(stacktd.length()-1);
                           Stack.pop();
						   Stack.push('G');
                           Stack.push('T');
						   stacktd=stacktd+"GT";//将输入栈中的内容加到stacktd中
						   cout<<line<<"\t"<<stacktd<<"\t";
		                   OutputString(s);
		                   cout<<"\t\t"<<"E->TG"<<"\t\t"<<"POP,PUSH(GT)"<<endl;

					   }
				   else{
                       cout<<"\tError"<<endl;
					   count=s.size();
				   }
					   }break;
			   case'T' :{if(ch1=='('||ch1=='i'){
				             stacktd.erase(stacktd.length()-1);
                             Stack.pop();
                             Stack.push('S');
							 Stack.push('F');
                             stacktd=stacktd+"SF";
							 cout<<line<<"\t"<<stacktd<<"\t";
		                     OutputString(s);
		                     cout<<"\t\t"<<"T->FS"<<"\t\t"<<"POP,PUSH(SF)"<<endl;

						}
				   else{
							 cout<<"\tError"<<endl;
                           count=s.size();
				   }
						}break;

               case'G' :{if(ch1=='+'){
				            stacktd.erase(stacktd.length()-1);
                            Stack.pop();
							Stack.push('G');
                             Stack.push('T');
							 Stack.push('+');
							 stacktd=stacktd+"GT+";
							 cout<<line<<"\t"<<stacktd<<"\t";
		                     OutputString(s);
		                     cout<<"\t\t"<<"G->+TG"<<"\t\t"<<"POP,PUSH(GT+)"<<endl;

						}
				   else if(ch1=='-'){
					   stacktd.erase(stacktd.length()-1);
					   Stack.pop();
					   Stack.push('G');
					   Stack.push('T');
					   Stack.push('-');
                       stacktd=stacktd+"GT-";
					   cout<<line<<"\t"<<stacktd<<"\t";
		               OutputString(s);
		               cout<<"\t\t"<<"G->-TG"<<"\t\t"<<"POP,PUSH(GT-)"<<endl;

				   }
				   else if(ch1==')'||ch1=='#'){
					   stacktd.erase(stacktd.length()-1);
					   Stack.pop();
					   cout<<line<<"\t"<<stacktd<<"\t";
		               OutputString(s);
		               cout<<"\t\t"<<"G->ε"<<"\t\t"<<"POP"<<endl;

				   }
				   else{
						cout<<"\tError"<<endl;
				   count=s.size();
				   }
						}break;
               case'F' :{if(ch1=='('){
				       stacktd.erase(stacktd.length()-1);
				       Stack.pop();
				       Stack.push(')');
					   Stack.push('E');
					   Stack.push('(');
					   stacktd=stacktd+")E(";
					   cout<<line<<"\t"<<stacktd<<"\t";
		               OutputString(s);
		               cout<<"\t\t"<<"F->(E)"<<"\t\t"<<"POP,PUSH()E()"<<endl;
					   //cout<<")E("<<endl;
						}
				   else  if(ch1=='i'){
					   stacktd.erase(stacktd.length()-1);
					   Stack.pop();
					   Stack.push('i');
                       stacktd=stacktd+"i";
					   cout<<line<<"\t"<<stacktd<<"\t";
		               OutputString(s);
		               cout<<"\t\t"<<"F->i"<<"\t\t"<<"POP,PUSH(i)"<<endl;
				   }
				   else{
                       cout<<"\tError"<<endl;
                       count=s.size();
					   }
						}break;
               case'S' :{if(ch1=='*'){
				            stacktd.erase(stacktd.length()-1);
                            Stack.pop();
							Stack.push('S');
							Stack.push('F');
							Stack.push('*');
							stacktd=stacktd+"SF*";
							cout<<line<<"\t"<<stacktd<<"\t";
		                    OutputString(s);
		                    cout<<"\t\t"<<"S->*FS"<<"\t\t"<<"POP,PUSH(SF*)"<<endl;
						}
				   else if(ch1=='/'){
					   stacktd.erase(stacktd.length()-1);
					   Stack.pop();
					   Stack.push('S');
					   Stack.push('F');
					   Stack.push('/');
					   stacktd=stacktd+"SF/";
					   cout<<line<<"\t"<<stacktd<<"\t";
		               OutputString(s);
		               cout<<"\t\t"<<"S->/FS"<<"\t\t"<<"POP,PUSH(SF/)"<<endl;
				   }
				   else if(ch1=='+'||ch1=='#'||ch1=='-'||ch1==')'){
					   stacktd.erase(stacktd.length()-1);
					   Stack.pop();
					   cout<<line<<"\t"<<stacktd<<"\t";
		               OutputString(s);
		               cout<<"\t\t"<<"S->ε"<<"\t\t"<<"POP"<<endl;
				   }
				   else{
						cout<<"\tError"<<endl;
				        count=s.size();
				   }
						}break;
			   default : {cout<<ch<<"\tError"<<endl;
				          count=s.size();
						 }


	 }
	 line++;
	}
}
int main(){
    // 设置控制台输出为UTF-8编码
    SetConsoleOutputCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);

	cout<<"************************LL(1)分析*************************"<<endl;
    cout<<"本分析文法产生式为"<<endl;
	for(int j=0;j<10;j++)
		cout<<Production[j]<<endl;
	cout<<"************************LL(1)分析表*************************"<<endl;
	cout<<"\t+\t-\t*\t/\t(\t)\ti\t#"<<endl;
	cout<<"E\t\t\t\t\tE->TG\t\tE->TG"<<endl;
	cout<<"T\t\t\t\t\tT->FS\t\tT->FS"<<endl;
	cout<<"G\tG->+TG\tG->-TG\t\t\t\tG->ε\t\tG->ε"<<endl;
    cout<<"F\t\t\t\t\tF->(E)\t\tF->i"<<endl;
	cout<<"S\tS->ε\tS->ε\tS->*FS\tS->/FS\t\tS->ε\t\tS->ε"<<endl;
	string Sstring;
	char T;
do{
	cout<<"输入字符串"<<endl;
	cin>>Sstring;//输入要分析的字符串
	cout<<"************************现进行如下分析*************************"<<endl;
	cout<<"步骤"<<"\t"<<"分析栈"<<"\t"<<"剩余输入串"<<"\t"<<"所用产生式"<<"\t"<<"动作"<<endl;
    Analyse(Sstring);
	count=0;//记录当前进行处理的输入字符串字符位置
    line=0;//记录处理的步骤数
    stacktd="#E";
    while(!Stack.empty()){
		cout<<Stack.top();
		Stack.pop();
	}
    cout<<"是否继续分析,Y或y继续"<<endl;
	cin>>T;
	}while(T=='y'||T=='Y');
    return 0;
}
