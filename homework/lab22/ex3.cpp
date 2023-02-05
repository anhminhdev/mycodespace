/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

// ###INSERT CODE HERE -
struct DATE
{
    int day, month, year;
};

typedef struct CHUYENBAY
{
    string ma;
    DATE ngay;
    float gio;
    string noiden;
} CB;

void nhapThongTin1CB(CB &x)
{
    getline(cin, x.ma);
    cin >> x.ngay.day >> x.ngay.month >> x.ngay.year;
    cin >> x.gio;
    cin.ignore();
    getline(cin, x.noiden);
}

void nhapDSChuyenBay(CB a[], int &n)
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        nhapThongTin1CB(a[i]);
    }
}

void xuatChuyenBayToiTinh(CB a[], int n, string hn)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].noiden.compare(hn) == 0)
        {
            cout << a[i].ma << "\t"
                 << a[i].ngay.day << "/" << a[i].ngay.month << "/" << a[i].ngay.year << "\t"
                 << a[i].gio << "\t"
                 << a[i].noiden;
        }
        cout << endl;
    }
}

int main()
{
    CB a[100];
    int n;

    nhapDSChuyenBay(a, n); // Nhap danh sach cac chuyen bay

    cout << "Machuyen\t|Ngaybay\t|Giobay\t|Noiden\n";
    xuatChuyenBayToiTinh(a, n, "Ha Noi");

    return 0;
}
