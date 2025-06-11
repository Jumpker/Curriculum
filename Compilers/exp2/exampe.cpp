#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 状态转移表
int Pas_aut[8][5] = {
    // 0-9  .   e/E  +/- other
    {2,   0,   0,   0,   0}, // 1
    {2,   3,   5,   0,   8}, // 2
    {4,   0,   0,   0,   0}, // 3
    {4,   0,   5,   0,   8}, // 4
    {7,   0,   0,   6,   0}, // 5
    {7,   0,   0,   0,   0}, // 6
    {7,   0,   0,   0,   8}, // 7
    {0,   0,   0,   0,   0}  // 8
};

string line; // 输入字符串

class PascalCons
{
private:
    int aut[8][5];      // 状态转移表
    int s;              // 当前状态
    int n, p, m, e, t;  // 尾数、指数、小数位数、指数符号、是否含小数
    double num;         // 结果
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
    if (ch >= '0' && ch <= '9')
        return 0;
    else if (ch == '.')
        return 1;
    else if (ch == 'E' || ch == 'e')
        return 2;
    else if (ch == '+' || ch == '-')
        return 3;
    else
        return 4;
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
        p = 0;
        m = 0;
        e = 1;
        t = 0;
        num = 0;
        break;
    case 2:
        n = 10 * n + (ch - '0');
        break;
    case 3:
        t = 1;
        break;
    case 4:
        n = 10 * n + (ch - '0');
        m++;
        break;
    case 5:
        // 进入指数部分
        break;
    case 6:
        if (ch == '-')
            e = -1;
        else if (ch == '+')
            e = 1;
        break;
    case 7:
        p = 10 * p + (ch - '0');
        break;
    case 8:
        num = n * pow(10, e * p - m);
        break;
    }
}

double PascalCons::number(int* pos)
{
    s = 1;
    act(s, ' '); // 初始化

    while (true)
    {
        if (*pos >= line.length()) break;

        ch = line[*pos];
        (*pos)++;

        int next_s = find(s, ch);
        if (next_s == 0) break;

        s = next_s;
        act(s, ch);

        if (s == 8) break;
    }

    if (s == 8)
        return num;
    else
    {
        ProcError();
        return 0;
    }
}

int main()
{
    PascalCons a;

    while (true)
    {
        cout << "please input a number: ";
        getline(cin, line);
        if (line.empty()) break;
        line += ' '; // 结束符，模拟空格
        int i_line = 0;
        cout << a.number(&i_line) << endl;
    }

    return 0;
}
