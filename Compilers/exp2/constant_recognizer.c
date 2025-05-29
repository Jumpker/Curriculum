#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// 定义DFA状态
enum State {
    STATE_START = 0,    // 初始状态
    STATE_INT,          // 整数状态
    STATE_DOT,          // 遇到小数点后的状态
    STATE_FLOAT,        // 浮点数状态
    STATE_EXP,          // 遇到'e'或'E'后的状态
    STATE_EXP_SIGN,     // 科学计数法指数符号后的状态
    STATE_EXP_NUM,      // 科学计数法指数数字后的状态
    STATE_ACCEPT,       // 接受状态
    STATE_ERROR         // 错误状态
};

// 定义字符类型
enum CharType {
    CHAR_DIGIT,         // 数字 (0-9)
    CHAR_DOT,           // 小数点 (.)
    CHAR_E,             // 科学计数法符号 (e/E)
    CHAR_SIGN,          // 符号 (+/-)
    CHAR_OTHER,         // 其他字符
    CHAR_END            // 字符串结束符 (\0)
};

// 获取字符类型
enum CharType getCharType(char c) {
    if (isdigit(c)) {
        return CHAR_DIGIT;
    } else if (c == '.') {
        return CHAR_DOT;
    } else if (c == 'e' || c == 'E') {
        return CHAR_E;
    } else if (c == '+' || c == '-') {
        return CHAR_SIGN;
    } else if (c == '\0') {
        return CHAR_END;
    } else {
        return CHAR_OTHER;
    }
}

// 状态转移表
// [当前状态][字符类型] -> 下一个状态
enum State transitionTable[9][6] = {
    // CHAR_DIGIT, CHAR_DOT, CHAR_E, CHAR_SIGN, CHAR_OTHER, CHAR_END
    {STATE_INT,    STATE_DOT,  STATE_ERROR, STATE_ERROR, STATE_ERROR,  STATE_ERROR}, // STATE_START (0)
    {STATE_INT,    STATE_FLOAT,STATE_EXP,   STATE_ERROR, STATE_ERROR,  STATE_ACCEPT},  // STATE_INT (1)
    {STATE_FLOAT,  STATE_ERROR,STATE_ERROR, STATE_ERROR, STATE_ERROR,  STATE_ERROR}, // STATE_DOT (2) - 初始图示有误，应为STATE_FLOAT
    {STATE_FLOAT,  STATE_ERROR,STATE_EXP,   STATE_ERROR, STATE_ERROR,  STATE_ACCEPT},  // STATE_FLOAT (3)
    {STATE_EXP_NUM,STATE_ERROR,STATE_ERROR, STATE_EXP_SIGN,STATE_ERROR,  STATE_ERROR}, // STATE_EXP (4)
    {STATE_EXP_NUM,STATE_ERROR,STATE_ERROR, STATE_ERROR, STATE_ERROR,  STATE_ERROR}, // STATE_EXP_SIGN (5)
    {STATE_EXP_NUM,STATE_ERROR,STATE_ERROR, STATE_ERROR, STATE_ERROR,  STATE_ACCEPT},  // STATE_EXP_NUM (6)
    {STATE_ACCEPT, STATE_ACCEPT,STATE_ACCEPT,STATE_ACCEPT,STATE_ACCEPT, STATE_ACCEPT}, // STATE_ACCEPT (7) - 接受状态，任何输入都保持接受
    {STATE_ERROR,  STATE_ERROR,STATE_ERROR, STATE_ERROR, STATE_ERROR,  STATE_ERROR}  // STATE_ERROR (8)
};

// 检查是否为接受状态
int isAcceptState(enum State s) {
    return (s == STATE_INT || s == STATE_FLOAT || s == STATE_EXP_NUM || s == STATE_ACCEPT);
}

// 识别常数类型
const char* recognizeConstant(const char* input) {
    enum State currentState = STATE_START;
    int i = 0;

    while (currentState != STATE_ERROR && input[i] != '\0') {
        enum CharType charType = getCharType(input[i]);

        // 特殊处理：状态4经由其他字符（-1）应转移至状态8
        if (currentState == STATE_EXP && charType == CHAR_OTHER) {
            currentState = STATE_ERROR; // 状态4遇到其他字符转移到状态8 (错误状态)
        } else {
            currentState = transitionTable[currentState][charType];
        }
        i++;
    }

    if (isAcceptState(currentState)) {
        // 进一步判断具体类型
        // 重新遍历，判断最终停留在哪个接受状态
        currentState = STATE_START;
        i = 0;
        while (input[i] != '\0') {
            enum CharType charType = getCharType(input[i]);
            if (currentState == STATE_EXP && charType == CHAR_OTHER) {
                currentState = STATE_ERROR; // 如果是有效常数，则不应发生
                break;
            }
            currentState = transitionTable[currentState][charType];
            i++;
        }

        if (currentState == STATE_INT) {
            return "整数常数";
        } else if (currentState == STATE_FLOAT) {
            return "浮点常数";
        } else if (currentState == STATE_EXP_NUM) {
            return "科学计数法常数";
        } else {
            return "有效常数 (通用)"; // 如果不是特定类型，则回退到接受状态
        }
    } else {
        return "非法常数";
    }
}

// 测试函数
void testRecognizer(const char* input, const char* expected) {
    const char* result = recognizeConstant(input);
    printf("输入: \"%s\"\n", input);
    printf("结果: %s\n", result);
    printf("预期: %s\n", expected);
    if (strcmp(result, expected) == 0) {
        printf("测试通过!\n\n");
    } else {
        printf("测试失败!\n\n");
    }
}

int main() {
    printf("常数识别程序测试用例:\n\n");

    // 合法常数
    testRecognizer("123", "整数常数");
    testRecognizer("123.", "浮点常数"); // 123. 应该被识别为浮点数
    testRecognizer("123.45", "浮点常数");
    testRecognizer(".45", "浮点常数"); // .45 应该被识别为浮点数
    testRecognizer("0.", "浮点常数");
    testRecognizer("0.0", "浮点常数");
    testRecognizer("1e+0", "科学计数法常数");
    testRecognizer("1.e1", "科学计数法常数"); // 1.e1 应该被识别为科学计数法
    testRecognizer(".1e1", "科学计数法常数"); // .1e1 应该被识别为科学计数法
    testRecognizer("1e5", "科学计数法常数");
    testRecognizer("1.2e-3", "科学计数法常数");
    testRecognizer("1.2E+3", "科学计数法常数");
    testRecognizer("123e+4", "科学计数法常数");

    // 非法常数
    testRecognizer("abc", "非法常数");
    testRecognizer("123a", "非法常数");
    testRecognizer("1.2.3", "非法常数");
    testRecognizer("1e", "非法常数");
    testRecognizer("1e+", "非法常数");
    testRecognizer("+", "非法常数");
    testRecognizer("-", "非法常数");
    testRecognizer("e123", "非法常数");
    testRecognizer("1e+\0", "非法常数"); // 确保处理到字符串结束符
    testRecognizer("1e-a", "非法常数"); // 状态4经由其他字符（-1）应转移至状态8

    return 0;
}