#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 状态转移表
int Pas_aut[3][3] = {
    // 0   1   other
    {2,  2,  0}, // 1 (初始状态)
    {2,  2,  3}, // 2 (接收数字状态)
    {0,  0,  0}  // 3 (接受状态)
};

std::string line; // 输入字符串

class PascalCons
{
private:
    int aut[3][3];      // 状态转移表
    int s;              // 当前状态
    int n;              // 结果数值
    char ch;            // 当前字符

public:
    PascalCons();
    double number(int* i);

private:
    void ProcError();
    int map(char ch);
    int find(int s, char ch);
    void act(int s, char ch);
};

PascalCons::PascalCons()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 5; j++)
            aut[i][j] = Pas_aut[i][j];
    ch = ' ';
}

void PascalCons::ProcError()
{
    cout << "Error: Invalid constant format." << endl;
}

int PascalCons::map(char ch)
{
    if (ch == '0')
        return 0;
    else if (ch == '1')
        return 1;
    else
        return 2; // 其他字符（如空格、结尾标志）
}

int PascalCons::find(int s, char ch)
{
    int i = s - 1;
    int j = map(ch);
    return aut[i][j];
}

void PascalCons::act(int s, char ch)
{
    switch (s)
    {
    case 1:
        n = 0;
        break;
    case 2:
        n = n * 2 + (ch - '0');
        break;
    }
}

double PascalCons::number(int *p)
{
    s = 1;
    act(s, ' '); // 初始化动作

    while (true)
    {
        if (*p >= line.length()) break;

        ch = line.at(*p);
        (*p)++;

        int next_s = find(s, ch);
        if (next_s == 0) break;

        s = next_s;
        act(s, ch);

        if (s == 3) break; // 接受状态
    }

    if (s == 3)
        return n;
    else {
        ProcError();
        return 0;
    }
}

int main()
{
    PascalCons a;

    while (true)
    {
        cout << "please input a binary number: ";
        std::getline(std::cin, line);
        line += ' '; // 添加结束标志空格
        int i_line = 0; // 每次重新初始化指针
        double result = a.number(&i_line);
        if (result == 0 && i_line == 0 && line.length() == 1) { // 处理空输入
            // 不做任何处理，继续下一次循环
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
