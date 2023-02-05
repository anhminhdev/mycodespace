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

int middleOfArray(int a[], int n)
{
  // n is odd number
  if (n % 2 != 0)
  {
    return a[n / 2];
  }
  // n is even number
  else
  {
    return a[n / 2] + a[(n / 2) - 1];
  }
}

int main()
{
  int a[100000], n;
  inputArray(a, n);
  if (a[0] == a[n - 1] && a[0] == middleOfArray(a, n))
    cout << 1;
  else
    cout << 0;
  return 0;
}