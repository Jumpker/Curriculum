#include<iostream>
#include<stack>
#include<string>
using namespace std;
string Production[10]={"E->TG","G->+TG","G->-TG","G->��","T->FS","S->*FS","S->/FS","S->��","F->(E)","F->i"};//����ʽ����
char termina[8]={'+','-','*','/','(',')','i','#'};//�ս������
char nontermina[5]={'E','T','G','F','S'};//���ս������
int count=0;//��¼��ǰ���д����������ַ����ַ�λ��
int line=0;//��¼�����Ĳ�����
string stacktd="#E";//��¼ջ������
stack <char> Stack;//����һ��ջ
char ch,ch1;//ch��¼ջ���ַ���ch1��¼��ǰ���д����������ַ����ַ�

int Istermina(char c){//�ж����Ƿ�Ϊ�ս��
	for(int i=0;i<8;i++){
    if(termina[i]==c)
		return 1;
	}
	return 0;
}
int Isnontermina(char c){//�ж����Ƿ�Ϊ���ս��
	for(int i=0;i<5;i++){
    if(nontermina[i]==c)
		return 1;
	}
	return 0;
}
void OutputString(string s){//���δ�������ַ���
	for(int i=count;i<s.size();i++)
		cout<<s.at(i);
}
void Analyse(string s){//��������
    s=s+"#";
	Stack.push('#');//��ʼ��
    Stack.push('E');
	cout<<line<<"\t"<<stacktd<<"\t";
    OutputString(s);
    cout<<"\t\t"<<"\t\t"<<"��ʼ��"<<endl;
	line++;
	while(count<s.size()){//ѭ�����������봮�Ƿ񱻴�����ȫ

    ch=Stack.top();
	ch1=s.at(count);

	if(Istermina(ch)){
		if(ch==ch1&&ch!='#'){
         stacktd.erase(stacktd.length()-1);//ɾ��stacktd�ַ�����β��ĸ
		 Stack.pop();
	     count++;
		 cout<<line<<"\t"<<stacktd<<"\t";
		 OutputString(s);
		 cout<<"\t\t"<<"\t\t"<<"GETNEXT("<<ch<<")"<<endl;

		}
		else if(ch='#'){
			cout<<"acc"<<"\t�����ɹ�"<<endl;//��ʾ������ɣ����봮Ϊ���ķ�����ȷ����
			count=s.size();
		}
		else{
        cout<<"\tError"<<endl;//��ʾ���봮Ϊ���ķ��ķǷ�����
		count=s.size();//ʹѭ������

		}
	}
	else switch(ch){//switch��䣬����������ս��������봮�ľ���ִ�����
               case'E':{if(ch1=='('||ch1=='i'){
				           stacktd.erase(stacktd.length()-1);
                           Stack.pop();
						   Stack.push('G');
                           Stack.push('T');
						   stacktd=stacktd+"GT";//������ջ�е����ݼӵ�stacktd��
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
		               cout<<"\t\t"<<"G->��"<<"\t\t"<<"POP"<<endl;

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
		               cout<<"\t\t"<<"S->��"<<"\t\t"<<"POP"<<endl;
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
	cout<<"************************LL(1)����*************************"<<endl;
    cout<<"�������ķ�����ʽΪ"<<endl;
	for(int j=0;j<10;j++)
		cout<<Production[j]<<endl;
	cout<<"************************LL(1)������*************************"<<endl;
	cout<<"\t+\t-\t*\t/\t(\t)\ti\t#"<<endl;
	cout<<"E\t\t\t\t\tE->TG\t\tE->TG"<<endl;
	cout<<"T\t\t\t\t\tT->FS\t\tT->FS"<<endl;
	cout<<"G\tG->+TG\tG->-TG\t\t\t\tG->��\t\tG->��"<<endl;
    cout<<"F\t\t\t\t\tF->(E)\t\tF->i"<<endl;
	cout<<"S\tS->��\tS->��\tS->*FS\tS->/FS\t\tS->��\t\tS->��"<<endl;
	string Sstring;
	char T;
do{
	cout<<"�����ַ���"<<endl;
	cin>>Sstring;//����Ҫ�������ַ���
	cout<<"************************�ֽ������·���*************************"<<endl;
	cout<<"����"<<"\t"<<"����ջ"<<"\t"<<"ʣ�����봮"<<"\t"<<"���ò���ʽ"<<"\t"<<"����"<<endl;
    Analyse(Sstring);
	count=0;//��¼��ǰ���д����������ַ����ַ�λ��
    line=0;//��¼�����Ĳ�����
    stacktd="#E";
    while(!Stack.empty()){
		cout<<Stack.top();
		Stack.pop();
	}
    cout<<"�Ƿ��������,Y��y����"<<endl;
	cin>>T;
	}while(T=='y'||T=='Y');
    return 0;
}

