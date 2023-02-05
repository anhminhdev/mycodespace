/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

using namespace std;

// ###INSERT CODE HERE -

bool is_cube(int n)
{
    if (n == 0 || n == 1)
        return true;
    for (int i = 2; i * i * i <= n; i++)
    {
        if (i * i * i == n)
            return true;
    }
    return false;
}

int inputArray(int a[], int &n)
{
    cin >> n;
    if (n < 1)
    {
        cout << "Mang rong";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    return 69;
}

void outputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

void listOfCubesWithEvenIndex(int a[], int n)
{
    int count(0);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && is_cube(a[i]))
        {
            cout << a[i] << ' ';
            count++;
        }
    }
    if (count == 0)
        cout << "Mang khong co so lap phuong o vi tri chan";
    else
        cout << "\nCo " << count << " so thoa dieu kien";
}

int main()
{
    int n, a[100];
    int i = inputArray(a, n); // i=0 thi nhap khong thanh cong, mang rong, i khac 0 thi mang co phan tu
    if (i != 0)               // nhap thanh cong
    {
        cout << "Mang vua nhap:" << endl;
        outputArray(a, n);
        cout << endl;
        cout << "Danh sach cac so lap phuong o vi tri chan:" << endl;
        listOfCubesWithEvenIndex(a, n);
    }
    return 0;
}
