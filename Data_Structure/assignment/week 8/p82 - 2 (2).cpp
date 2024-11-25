//(2)������ָ��������������ͬ���ַ����У��硰abba���͡�abdba��
//���ǻ��ģ�����good�����ǻ��ġ�������㷨�ж��������ַ�����
//�Ƿ�Ϊ���ġ�����ʾ����һ���ַ���ջ����
#include <stdio.h>  
#include "sqstack.cpp" 
// �ж��ַ����Ƿ�Ϊ����  
bool isPalindrome(const char *str) {  
    Stack s;  
    initStack(&s);  
    int len = strlen(str);  
    int mid = len / 2;  
  
    // ��ǰ�벿���ַ�ѹ��ջ��  
    for (int i = 0; i < mid; i++) {  
        push(&s, str[i]);  
    }  
  
    // ����ַ�������Ϊ�������������м��ַ�  
    if (len % 2 != 0) {  
        mid++;  
    }  
  
    // �Ӻ�벿�ֿ�ʼ�Ƚ��ַ�  
    for (int i = mid; i < len; i++) {  
        if (pop(&s) != str[i]) {  
            return false;  
        }  
    }  
  
    return true;  
}  
  
int main() {  
    char str[MAX_SIZE];  
    printf("������һ���ַ�����");  
    scanf("%s", str);  
  
    if (isPalindrome(str)) {  
        printf("�ַ����ǻ��ġ�\n");  
    } else {  
        printf("�ַ������ǻ��ġ�\n");  
    }  
  
    return 0;  
}
