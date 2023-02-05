#include "hocSinh.h"

void HocSinh::nhap()
{
    fflush(stdin);
    cout << "\nNhap ten: ";
    getline(cin, ten);

    do
    {
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
        if (diemToan < 0 || diemToan > 10)
            cout << "\nDiem Toan nhap vao khong hop le. Vui long nhap lai!" << endl;
    } while (diemToan < 0 || diemToan > 10);

    do
    {
        cout << "Nhap diem Van: ";
        cin >> diemVan;
        if (diemVan < 0 || diemVan > 10)
            cout << "\nDiem Van nhap vao khong hop le. Vui long nhap lai!" << endl;
    } while (diemVan < 0 || diemVan > 10);
}

void HocSinh::xuat()
{
    cout << "\n=====Thong tin hoc sinh=====\n";
    cout << "Ten hoc sinh: " << ten << endl;
    cout << "Diem Toan: " << diemToan << endl;
    cout << "Diem Van: " << diemVan << endl;
    cout << "Diem trung binh: " << tinhDiemTrungBinh() << endl;
}

double HocSinh::tinhDiemTrungBinh()
{
    return (diemToan + diemVan) / 2.0;
}

int main()
{
    HocSinh hs1;
    hs1.nhap();
    hs1.xuat();
    return 0;
}