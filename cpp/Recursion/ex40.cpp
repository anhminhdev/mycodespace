#include <iostream>
using namespace std;
#include <math.h>

// Tính S(n) = 1 + 1*2 + 1*2*3 + ... + 1*2*3*n

// Cách 1: Khử đệ quy
unsigned long khuDeQuy(int n)
{
    unsigned long sum(0), t(1);
    for (int i = 1; i <= n; i++)
    {
        t *= i;
        sum += t;
    }
    return sum;
}

// Cách 2: đệ quy thường
long giaiThua(int n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}
double deQuyThuong(int n)
{
    if (n == 1)
        return 1;
    return giaiThua(n) + deQuyThuong(n - 1);
}

// Cách 3: đệ quy phi tuyến: là có dùng vòng lặp trong hàm đệ quy
double deQuyPhiTuyen(int n)
{
    if (n == 1)
        return 1;
    int tich(1);
    for (int i = 1; i <= n; i++)
    {
        tich *= i;
    }
    return tich + deQuyPhiTuyen(n - 1);
}

int main()
{
    cout << "Khu de quy: " << khuDeQuy(5) << endl;
    cout << "De quy thuong: " << deQuyThuong(5) << endl;
    cout << "De quy phi tuyen: " << deQuyPhiTuyen(5) << endl;
    return 0;
}