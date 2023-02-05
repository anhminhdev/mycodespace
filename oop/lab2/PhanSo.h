#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo(int numerator, int denominator);
    void nhap();
    void xuat();
    double ketQuaPhanSo();
    int UCLN(int, int);
    void rutGonPhanSo();
    // PhanSo tinhTong(PhanSo);
    // PhanSo tinhHieu(PhanSo);
    // PhanSo tinhTich(PhanSo);
    // PhanSo tinhThuong(PhanSo);

    // 1 số nguyên cộng với 1 phân số
    friend PhanSo operator+(int, PhanSo);

    // cài đặt toán tử nhập cho phân số
    friend istream &operator>>(istream &, PhanSo &);
    // cài đặt toán tử xuất cho phân số
    friend ostream &operator<<(ostream &, PhanSo);
    // cài toán tử =
    PhanSo &PhanSo::operator=(const PhanSo);    
};
