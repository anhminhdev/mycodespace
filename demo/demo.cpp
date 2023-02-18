#include <iostream>
#include <cmath>
using namespace std;
int n, a[100], b[100], k;

void inputArray()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

void quickSort(int a[], int l, int r)
{
  int p = a[(l + r) / 2]; // pivot element at mid array
  int i = l, j = r;
  while (i < j)
  {
    while (a[i] < p)
    {
      i++;
    }
    while (a[j] > p)
    {
      j--;
    }
    if (i <= j)
    {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }
  if (i < r)
  {
    quickSort(a, i, r);
  }
  if (l < j)
  {
    quickSort(a, l, j);
  }
}

void printArray()
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
}

int main()
{
  inputArray();
  // get non-zero element in array a
  k = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != 0)
    {
      b[k++] = a[i];
    }
  }
  quickSort(b, 0, k - 1);
  k = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] < 0)
    {
      a[i] = b[k++];
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (a[i] > 0)
    {
      a[i] = b[k++];
    }
  }
  printArray();
  return 0;
}