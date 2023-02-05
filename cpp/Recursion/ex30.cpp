#include <iostream>
using namespace std;

// Tính tổng từ 1 đến n

// Cách 1: đệ quy thường
unsigned int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

// Cách 2: đệ quy đuôi
unsigned int deQuyDuoi(int n, unsigned int res = 1)
{
    if (n == 1)
        return res;
    return deQuyDuoi(n - 1, res + n);
}
int main()
{
    // So sánh thời gian chạy của 2 cách đệ quy thường với đệ quy đuôi

    clock_t start1 = clock(); // Bắt đầu thời gian
    for (int i = 1; i <= 999999; i++)
    {
        sum(100);
    }
    clock_t finish1 = clock(); // Thời gian kết thúc

    clock_t start2 = clock(); // Bắt đầu thời gian
    for (int i = 1; i <= 999999; i++)
    {
        deQuyDuoi(100);
    }
    clock_t finish2 = clock(); // Thời gian kết thúc

    cout << "Thoi gian chay de quy thuong: " << (double)(finish1 - start1) / CLOCKS_PER_SEC << endl;
    cout << "Thoi gian chay de quy duoi: " << (double)(finish2 - start2) / CLOCKS_PER_SEC << endl;
    return 0;
}