/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

// ###INSERT CODE HERE -
using namespace std;

void inputArray(int a[], int &n)
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void deleteOneElement(int a[], int &n, int pos)
{
  for (int i = n - 1; i >= 0; i--)
  {
    if (i == pos)
    {
      for (int j = i; j < n - 1; j++)
      {
        a[j] = a[j + 1];
      }
      n--;
      break;
    }
  }
}

void outputArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
}
int main()
{
  int a[10000], n;
  inputArray(a, n);
  // n is odd number
  if (n % 2 != 0)
  {
    outputArray(a, n);
  }
  // n is even number
  else
  {
    int sum = a[n / 2] + a[n / 2 - 1];
    a[n / 2] = sum;
    a[n / 2 - 1] = sum;
    deleteOneElement(a, n, n / 2);
    outputArray(a, n);
  }
  return 0;
}