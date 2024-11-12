//(2)回文是指正读、反读均相同的字符序列，如“abba”和“abdba”
//均是回文，但“good”不是回文。试设计算法判定给定的字符序列
//是否为回文。（提示：将一半字符入栈。）
#include <stdio.h>  
#include "sqstack.cpp" 
// 判断字符串是否为回文  
bool isPalindrome(const char *str) {  
    Stack s;  
    initStack(&s);  
    int len = strlen(str);  
    int mid = len / 2;  
  
    // 将前半部分字符压入栈中  
    for (int i = 0; i < mid; i++) {  
        push(&s, str[i]);  
    }  
  
    // 如果字符串长度为奇数，则跳过中间字符  
    if (len % 2 != 0) {  
        mid++;  
    }  
  
    // 从后半部分开始比较字符  
    for (int i = mid; i < len; i++) {  
        if (pop(&s) != str[i]) {  
            return false;  
        }  
    }  
  
    return true;  
}  
  
int main() {  
    char str[MAX_SIZE];  
    printf("请输入一个字符串：");  
    scanf("%s", str);  
  
    if (isPalindrome(str)) {  
        printf("字符串是回文。\n");  
    } else {  
        printf("字符串不是回文。\n");  
    }  
  
    return 0;  
}
