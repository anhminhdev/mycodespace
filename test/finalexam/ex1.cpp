/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
void nhapMang(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void xuatMang(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
}

int soChanLonNhat(int a[], int n)
{
  int max;
  int f = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {
      max = a[i];
      f = 1;
    }
  }
  // tim max chan lon nhat
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0 && a[i] > max)
    {
      max = a[i];
    }
  }
  if (f == 0)
  {
    return -1;
  }
  else
    return max;
}

void inSoChanDauTien(int a[], int n)
{
  int first = 0, index = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {
      first = a[i];
      index = i;
      break;
    }
  }
  cout << first << " la so chan dau tien, co chi so " << index << " trong mang" << endl;
}

void inSoChanCuoiCung(int a[], int n)
{
  int last = 0, idx = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] % 2 == 0)
    {
      last = a[i];
      idx = i;
      break;
    }
  }
  cout << last << " la so chan cuoi cung, co chi so " << idx << " trong mang" << endl;
}

void viTriSoChan(int a[], int n)
{
  int res = soChanLonNhat(a, n);
  if (res == -1)
  {
    cout << "Mang khong co so chan";
  }
  else
  {
    inSoChanDauTien(a, n);
    inSoChanCuoiCung(a, n);
    cout << "So chan lon nhat: " << res;
  }
}

int main()
{
  int n, a[10000];
  cin >> n;
  nhapMang(a, n);
  cout << "Mang vua nhap:" << endl;
  xuatMang(a, n);
  cout << endl;
  viTriSoChan(a, n);
  return 0;
}
