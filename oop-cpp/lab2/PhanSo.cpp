#include "PhanSo.h"

void PhanSo::nhap()
{
    cout << "Nhap tu so: ";
    cin >> tu;

    do
    {
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0)
            cout << "Mau so nhap vao khong hop le. Vui long nhap lai mau so!" << endl;
    } while (mau == 0);
}

double PhanSo::ketQuaPhanSo()
{
    return (double)tu / mau;
}

void PhanSo::xuat()
{
    if (mau < 0)
    {
        tu *= -1;
        mau *= -1;
    }
    rutGonPhanSo();
    cout << tu << " / " << mau << endl;

    // cout << tu << " / " << mau << " = " << ketQuaPhanSo() << endl;

    // if (ketQuaPhanSo() < 0)
    //     cout << "Phan so am." << endl;
    // else if (ketQuaPhanSo() > 0)
    //     cout << "Phan so duong." << endl;
    // else
    //     cout << "Phan so = 0" << endl;
}

// Thuật toán Euclid tìm ƯCLN
int PhanSo::UCLN(int a, int b)
{
    abs(a);
    abs(b);
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

void PhanSo::rutGonPhanSo()
{
    int GCD = UCLN(tu, mau);
    tu /= GCD;
    mau /= GCD;
}

// PhanSo PhanSo::tinhTong(PhanSo ps2)
// {
//     PhanSo tong;
//     tong.tu = (this->tu * ps2.mau + ps2.tu * this->mau);
//     tong.mau = this->mau * ps2.mau;
//     return tong;
// }

// PhanSo PhanSo::tinhHieu(PhanSo ps2)
// {
//     PhanSo hieu;
//     hieu.tu = (this->tu * ps2.mau - ps2.tu * this->mau);
//     hieu.mau = this->mau * ps2.mau;
//     return hieu;
// }

// PhanSo PhanSo::tinhTich(PhanSo ps2)
// {
//     PhanSo tich;
//     tich.tu = this->tu * ps2.tu;
//     tich.mau = this->mau * ps2.mau;
//     return tich;
// }

// PhanSo PhanSo::tinhThuong(PhanSo ps2)
// {
//     PhanSo thuong;
//     thuong.tu = this->tu * ps2.mau;
//     thuong.mau = this->mau * ps2.tu;
//     return thuong;
// }

// PhanSo operator+(int n, PhanSo ps)
// {
//     PhanSo Tong;
//     Tong.tu = n * ps.mau + ps.tu;
//     Tong.mau = ps.mau;
//     return Tong;
// }

// cài đặt toán tử nhập cho phân số
istream &operator>>(istream &is, PhanSo &ps)
{
    cout << "Nhap tu so: ";
    is >> ps.tu;
    cout << "Nhap mau so: ";
    is >> ps.mau;
    return is;
}

// cài đặt toán tử xuất cho phân số
ostream &operator<<(ostream &os, PhanSo ps)
{
    os << ps.tu << " / " << ps.mau;
    return os;
}

PhanSo &PhanSo::operator=(const PhanSo ps)
{
    this->tu = ps.tu;
    this->mau = ps.mau;
    return *this;
}