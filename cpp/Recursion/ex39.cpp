#include <iostream>
using namespace std;
#include <math.h>

// Tính x^n

// Cách 1: đệ quy thường
double deQuyThuong(int x, int n)
{
    if (n > 0)
    {
        if (n == 1)
            return x;
        return x * deQuyThuong(x, n - 1);
    }
    else if (n < 0)
    {
        if (n == -1)
            return (1.0 / x);
        return (1.0 / x) * deQuyThuong(x, n + 1);
    }
    else // n == 0
        return 1;
}

// Cách 2: đệ quy đuôi
double deQuyDuoi(int x, int n, double res = 1)
{
    if (n > 0)
    {
        return deQuyDuoi(x, n - 1, res * x);
    }
    else if (n < 0)
    {
        return deQuyDuoi(x, n + 1, res * 1.0 / x);
    }
    // Điều kiện dừng nếu n == 0
    return res;
} 
int main()
{
    cout << "De quy thuong: " << deQuyThuong(2, -3) << endl;
    cout << "De quy duoi: " << deQuyDuoi(2, -3) << endl;
    return 0;
}