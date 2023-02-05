#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Nhap so nguyen duong n: ";
  cin >> n;
  if (n < 0)
  {
    n *= -1;
  }
  int a[100], na = 0;
  int i = 2;
  while (n != 1)
  {
    if (n % i == 0)
    {
      a[na++] = i;
      n /= i;
    }
    else
    {
      i++;
    }
  }
  // Print result
  for (int i = na - 1; i >= 0; i--)
  {
    cout << a[i];
    if (i != 0)
      cout << " x ";
  }
  return 0;
}