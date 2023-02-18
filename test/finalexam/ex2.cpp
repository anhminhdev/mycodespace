/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

#define MAX 500

void Nhapmang(int a[], int &n);
void Xuatmang(int a[], int n);
long long TichSole_VTSNT(int a[], int n);

int main()
{
  int a[MAX], n;
  Nhapmang(a, n);

  // ###INSERT CODE HERE -
  Xuatmang(a, n);
  if (n < 1)
    return 0;
  long long res = TichSole_VTSNT(a, n);
  if (res == -1)
  {
    cout << "Khong tim duoc so le o vi tri la so nguyen to, tich la: 0";
  }
  else
  {
    cout << "Tich cac so le o vi tri la so nguyen to la: " << res;
  }
}

void Nhapmang(int a[], int &n)
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void Xuatmang(int a[], int n)
{
  if (n < 1)
    cout << "Mang rong." << endl;
  else
  {
    for (int i = 0; i < n; i++)
    {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
}

long long TichSole_VTSNT(int a[], int n)
{
  long long res = 1;
  for (int i = 2; i < n; i++)
  {
    int f = 0;
    // check prime
    for (int j = 2; j <= sqrt(i); j++)
    {
      if (i % j == 0)
      {
        f = 1;
        break;
      }
    }
    if (f == 0) // i is prime
    {
      if (a[i] % 2 != 0)
      {
        res *= a[i];
      }
    }
  }
  if (res == 1)
  {
    return -1;
  }
  else
    return res;
}
