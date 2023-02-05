#include <iostream>
using namespace std;
#include <string>

class HocSinh
{
private:
    string ten;
    double diemToan, diemVan;

public:
    void nhap();
    void xuat();
    double tinhDiemTrungBinh();
};
