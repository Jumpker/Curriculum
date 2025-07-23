#include<iostream>
#include<stack>
#include<string>
#include<windows.h>
#include<io.h>
#include<fcntl.h>
using namespace std;

// 使用LR.cpp中的文法规则
wstring Production[6]={L"E->T", L"E->E+T", L"T->F", L"T->T*F", L"F->(E)", L"F->i"}; // 产生式集合
char termina[6]={'+', '*', '(', ')', 'i', '#'}; // 终结符集合
char nontermina[3]={'E', 'T', 'F'}; // 非终结符集合

int count=0; // 记录当前进行处理的输入字符串字符位置
int line=0; // 记录处理的步骤数
wstring stacktd=L"#E"; // 记录栈中内容
stack <char> Stack; // 创建一个栈
char ch, ch1; // ch记录栈顶字符，ch1记录当前进行处理的输入字符串字符

int Istermina(char c){ // 判断其是否为终结符
	for(int i=0; i<6; i++){
        if(termina[i]==c)
		return 1;
	}
	return 0;
}

int Isnontermina(char c){ // 判断其是否为非终结符
	for(int i=0; i<3; i++){
        if(nontermina[i]==c)
		return 1;
	}
	return 0;
}

void OutputString(wstring s){ // 输出未处理的字符串
	for(int i=count; i<s.size(); i++)
		wcout<<s.at(i);
}

void Analyse(wstring s){ // 分析过程
    s=s+L"#";
	Stack.push('#'); // 初始化
    Stack.push('E');
	wcout<<line<<L"\t"<<stacktd<<L"\t";
    OutputString(s);
    wcout<<L"\t\t"<<L"\t\t"<<L"初始化"<<endl;
	line++;
	while(count<s.size()){ // 循环条件，输入串是否被处理完全
        ch=Stack.top();
	ch1=s.at(count);

	if(Istermina(ch)){
		if(ch==ch1 && ch!='#'){
                stacktd.erase(stacktd.length()-1); // 删除stacktd字符串的尾字母
		 Stack.pop();
	         count++;
		 wcout<<line<<L"\t"<<stacktd<<L"\t";
		 OutputString(s);
		 wcout<<L"\t\t"<<L"\t\t"<<L"GETNEXT("<<ch<<L")"<<endl;
		}
		else if(ch=='#' && ch1=='#'){
			wcout<<L"acc"<<L"\t分析成功"<<endl; // 表示分析完成，输入串为该文法的正确句型
			count=s.size();
		}
		else{
                wcout<<L"\tError"<<endl; // 表示输入串为该文法的非法句型
		count=s.size(); // 使循环结束
		}
	}
	else switch(ch){ // switch语句，具体分析非终结符面对输入串的具体执行情况
               case'E':{
                   if(ch1=='(' || ch1=='i'){
		           stacktd.erase(stacktd.length()-1);
                           Stack.pop();
			   Stack.push('T');
			   stacktd=stacktd+L"T"; // 将输入栈中的内容加到stacktd中
			   wcout<<line<<L"\t"<<stacktd<<L"\t";
		           OutputString(s);
		           wcout<<L"\t\t"<<L"E->T"<<L"\t\t"<<L"POP,PUSH(T)"<<endl;
		   }
                   else if(ch1=='+'){
                       // 这种情况在LL(1)分析中不应该出现，因为E->E+T不是LL(1)文法
                       // 但我们可以通过左递归消除转换为E->TE'
                       wcout<<L"\tError: 左递归文法不适用于LL(1)分析"<<endl;
		       count=s.size();
                   }
		   else{
                       wcout<<L"\tError"<<endl;
			   count=s.size();
		   }
		   }break;
		   case'T':{
                   if(ch1=='(' || ch1=='i'){
		             stacktd.erase(stacktd.length()-1);
                             Stack.pop();
                             Stack.push('F');
			     stacktd=stacktd+L"F";
			     wcout<<line<<L"\t"<<stacktd<<L"\t";
		             OutputString(s);
		             wcout<<L"\t\t"<<L"T->F"<<L"\t\t"<<L"POP,PUSH(F)"<<endl;
			}
                   else if(ch1=='*'){
                       // 这种情况在LL(1)分析中不应该出现，因为T->T*F不是LL(1)文法
                       // 但我们可以通过左递归消除转换为T->FT'
                       wcout<<L"\tError: 左递归文法不适用于LL(1)分析"<<endl;
		       count=s.size();
                   }
		   else{
			     wcout<<L"\tError"<<endl;
                           count=s.size();
		   }
			}break;
               case'F':{
                   if(ch1=='('){
		       stacktd.erase(stacktd.length()-1);
		       Stack.pop();
		       Stack.push(')');
			   Stack.push('E');
			   Stack.push('(');
			   stacktd=stacktd+L")E(";
			   wcout<<line<<L"\t"<<stacktd<<L"\t";
		       OutputString(s);
		       wcout<<L"\t\t"<<L"F->(E)"<<L"\t\t"<<L"POP,PUSH()E()"<<endl;
			}
		   else if(ch1=='i'){
			   stacktd.erase(stacktd.length()-1);
			   Stack.pop();
			   Stack.push('i');
                       stacktd=stacktd+L"i";
			   wcout<<line<<L"\t"<<stacktd<<L"\t";
		       OutputString(s);
		       wcout<<L"\t\t"<<L"F->i"<<L"\t\t"<<L"POP,PUSH(i)"<<endl;
		   }
		   else{
                       wcout<<L"\tError"<<endl;
                       count=s.size();
			   }
			}break;
		   default:{
                       wcout<<ch<<L"\tError"<<endl;
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
    
    wcout<<L"************************LL(1)分析*************************"<<endl;
    wcout<<L"本分析文法产生式为"<<endl;
	for(int j=0; j<6; j++)
		wcout<<Production[j]<<endl;
	wcout<<L"注意：LR文法中的左递归产生式(E->E+T, T->T*F)不适用于LL(1)分析"<<endl;
	wcout<<L"************************LL(1)分析表*************************"<<endl;
	wcout<<L"\t+\t*\t(\t)\ti\t#"<<endl;
	wcout<<L"E\t\t\t\tE->T\t\tE->T"<<endl;
	wcout<<L"T\t\t\t\tT->F\t\tT->F"<<endl;
	wcout<<L"F\t\t\t\tF->(E)\t\tF->i"<<endl;
	string inputStr;
	wstring Sstring;
	char T;
    do{
	    wcout<<L"输入字符串"<<endl;
	    cin>>inputStr; // 输入要分析的字符串
	    // 将string转换为wstring
	    Sstring = wstring(inputStr.begin(), inputStr.end());
	    wcout<<L"************************现进行如下分析*************************"<<endl;
	    wcout<<L"步骤"<<L"\t"<<L"分析栈"<<L"\t"<<L"剩余输入串"<<L"\t"<<L"所用产生式"<<L"\t"<<L"动作"<<endl;
        Analyse(Sstring);
	    count=0; // 记录当前进行处理的输入字符串字符位置
        line=0; // 记录处理的步骤数
        stacktd=L"#E";
        while(!Stack.empty()){
		    Stack.pop();
	    }
        wcout<<L"是否继续分析,Y或y继续"<<endl;
	    cin>>T;
	}while(T=='y' || T=='Y');
    return 0;
}