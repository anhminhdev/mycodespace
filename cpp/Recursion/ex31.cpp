#include <iostream>
using namespace std;
#include <math.h>

// Tính tổng từ 1^2 đến n^2

// Cách 1: đệ quy thường
unsigned int sum(int n)
{
    if (n == 1)
        return 1;
    return pow(n, 2) + sum(n - 1);
}

// Cách 2: đệ quy đuôi
unsigned int deQuyDuoi(int n, unsigned int res = 1)
{
    if (n == 1)
        return res;
    return deQuyDuoi(n - 1, res + n * n);
}
int main()
{
    cout << sum(3) << ' ' << deQuyDuoi(3);
    return 0;
}