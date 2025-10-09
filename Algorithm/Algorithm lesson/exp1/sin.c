#include <stdio.h>
#include <stdlib.h>

double sin(double x) {
    double term = x; // 初始项
    double sum = x; // 累加和
    int n = 1; // 当前项的阶数

    // 使用泰勒级数展开计算sin(x)
    while (term > 1e-10 || term < -1e-10) {
        term = -term * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}

int main() {
    double x = 3.14159265358979323846*3/2;
    double result = sin(x);
    printf("sin(%lf) = %lf\n", x, result);

    return 0;
}