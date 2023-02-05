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

PhanSo cong(PhanSo ps1, PhanSo ps2)
{
    ps kq;
    kq.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
    kq.mauso = ps1.mauso * ps2.mauso;
    phanSoToiGian(kq);
    return kq;
}

PhanSo tru(PhanSo ps1, PhanSo ps2)
{
    ps kq;
    kq.tuso = ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso;
    kq.mauso = ps1.mauso * ps2.mauso;
    phanSoToiGian(kq);
    return kq;
}

PhanSo nhan(PhanSo ps1, PhanSo ps2)
{
    ps kq;
    kq.tuso = ps1.tuso * ps2.tuso;
    kq.mauso = ps1.mauso * ps2.mauso;
    phanSoToiGian(kq);
    return kq;
}

PhanSo chia(PhanSo ps1, PhanSo ps2)
{
    ps kq;
    if (ps1.tuso == 0 && ps2.tuso == 0)
    {
        kq.tuso = 0;
        kq.mauso = 0;
        return kq;
    }
    else
    {
        kq.tuso = ps1.tuso * ps2.mauso;
        kq.mauso = ps1.mauso * ps2.tuso;
    }
    phanSoToiGian(kq);
    return kq;
}

void InPhanSo(ps x)
{
    if (x.tuso < 0 && x.mauso < 0)
    {
        x.tuso *= -1;
        x.mauso *= -1;
    }
    cout << x.tuso << "/" << x.mauso;
}

int main()
{
    PhanSo ps1, ps2;
    cin >> ps1.tuso >> ps1.mauso;
    cin >> ps2.tuso >> ps2.mauso;
    char ch;
    cin >> ch;

    if (ps1.mauso == 0 || ps2.mauso == 0)
        cout << "Khong thoa yeu cau bai toan";
    else
    {
        switch (ch)
        {
        case '+':
        {
            ps kq = cong(ps1, ps2);
            InPhanSo(kq);
            break;
        }
        case '-':
        {
            ps kq = tru(ps1, ps2);
            InPhanSo(kq);
            break;
        }

        case '*':
        {
            ps kq = nhan(ps1, ps2);
            InPhanSo(kq);
            break;
        }

        case '/':
        {
            ps kq = chia(ps1, ps2);
            if (kq.tuso == 0 && kq.mauso == 0)
                cout << "Phep chia khong xac dinh";
            else
                InPhanSo(kq);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}