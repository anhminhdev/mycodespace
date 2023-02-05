#include <iostream>
using namespace std;
#include <math.h>

// Tính tổng từ 1/1 đến 1/n

// Cách 1: đệ quy thường
double sum(int n)
{
    if (n == 1)
        return 1;
    return 1.0 / n + sum(n - 1);
}

// Cách 2: đệ quy đuôi
double deQuyDuoi(int n, double res = 1)
{
    if (n == 1)
        return res;
    return deQuyDuoi(n - 1, res + 1.0 / n);
}
int main()
{
    cout << sum(3) << ' ' << deQuyDuoi(3);
    return 0;
}