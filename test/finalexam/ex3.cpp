/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
void inputArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void outputArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
}

bool isPrime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i <= n / 2; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

void filterPrimes(int a[], int na, int b[], int &nb, int m)
{
  nb = 0;
  int count = 0, f = 0;
  for (int i = 0; i < na; i++)
  {
    if (count == m)
      break;
    if (isPrime(a[i]))
    {
      f = 1;
      count++;
      b[nb++] = a[i];
    }
  }
  if (f == 0)
    cout << "Mang a khong chua so nguyen to" << endl;
  else if (count < m)
    cout << "Mang a khong co du " << m << " so nguyen to" << endl;
}

int main()
{
  int na, a[100], nb, b[100];
  cin >> na;
  inputArray(a, na);
  cout << "Mang a:" << endl;
  outputArray(a, na);
  cout << endl;
  int m;
  cin >> m;
  filterPrimes(a, na, b, nb, m); // tao ra mang b bang cach tach m so nguyen to tu a
  cout << "Mang b:" << endl;
  outputArray(b, nb);

  return 0;
}
