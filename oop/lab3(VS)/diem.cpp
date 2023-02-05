#include "diem.h"

void diem::nhap()
{
    cout << "Nhap toa do x: ";
    cin >> this->x;
    cout << "Nhap toa do y: ";
    cin >> this->y;
}

void diem::xuat()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

double diem::tinhKhoangCach(diem d2)
{
    return sqrt(pow(this->x - d2.x, 2) + pow(this->x - d2.y, 2));
}