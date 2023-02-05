#include "diem.h"

int main()
{
    diem d1(1, 2);
    diem d2(5, 8);
    diem d3;     // d3(0, 0)
    diem d4(d1); // copy private value d1 to d4

    cout << "Diem d1: ";
    d1.output();
    cout << "Diem d2: ";
    d2.output();
    cout << "Diem d3: ";
    d3.output();
    cout << "Diem d4: ";
    d4.output();
    return 0;
}