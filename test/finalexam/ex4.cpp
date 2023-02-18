
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

using namespace std;

// ###INSERT CODE HERE -
void inputArray(int a[], int &n)
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void printArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void reverseArray(int a[], int n)
{
  int mid = n / 2;
  int i = 0, j = n - 1;
  while (i < mid)
  {
    if (a[i] > a[j])
    {
      swap(a[i++], a[j--]);
    }
    else
    {
      i++;
    }
  }
  while (j > mid)
  {
    if (a[i] > a[j])
    {
      swap(a[i++], a[j--]);
    }
    else
    {
      j--;
    }
  }
}

int main()
{
  int a[100], n;
  inputArray(a, n);

  // In mang ban dau
  printArray(a, n);

  // Dao mang
  reverseArray(a, n);

  // In mang sau khi dao
  cout << "Reversed array is" << endl;
  printArray(a, n);

  return 0;
}
