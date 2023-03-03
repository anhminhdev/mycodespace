#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class diem
{
private:
    float x, y;

public:
    void nhap();
    void xuat();
    double tinhKhoangCach(diem);
};