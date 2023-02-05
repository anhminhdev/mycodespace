#include <iostream>
using namespace std;

typedef struct PhanSo
{
    int tuso, mauso;
} ps;

int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

void phanSoToiGian(PhanSo &x)
{
    int gcd = UCLN(x.tuso, x.mauso);
    x.tuso /= gcd;
    x.mauso /= gcd;
}

void xulydau(ps &x)
{
    if (x.mauso < 0 || (x.tuso < 0 && x.mauso < 0))
    {
        x.tuso *= -1;
        x.mauso *= -1;
    }
}

int main()
{
    ps ds[1000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ds[i].tuso >> ds[i].mauso;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (ds[i].mauso == 0)
        {
            cout << "Khong thoa yeu cau bai toan" << endl;
            continue;
        }
        if (ds[i].tuso == 0 && ds[i].mauso == 0)
        {
            cout << 0 << endl;
        }
        xulydau(ds[i]);
        phanSoToiGian(ds[i]);
        if (ds[i].tuso % ds[i].mauso == 0)
        {
            cout << ds[i].tuso / ds[i].mauso << endl;
        }
        else
            cout << ds[i].tuso << "/" << ds[i].mauso << endl;
    }
    return 0;
}