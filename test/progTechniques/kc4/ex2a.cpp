#include <iostream>
#include <algorithm>
using namespace std;

int n;     // the number of elements in array
double *a; // pointer manage array

void inputArray(double *&a, int &n)
{
  cout << "Enter the number of elements in array: ";
  cin >> n;
  a = new double[n];
  for (int i = 0; i < n; i++)
  {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
}

void outputArray()
{
  for (int i = 0; i < n; i++)
  {
    cout << *(a + i) << ' ';
  }
  cout << '\n';
}

int binarySearch(double key, int l, int r)
{
  if (l <= r)
  {
    int mid = (l + r) / 2;
    if (a[mid] == key)
    {
      return mid;
    }
    else if (key < a[mid])
    {
      return binarySearch(key, l, mid - 1);
    }
    else // key > a[mid]
    {
      return binarySearch(key, mid + 1, r);
    }
  }
  return -1;
}

int main()
{
  inputArray(a, n);
  sort(a, a + n);
  outputArray();
  int key;
  cout << "Enter value need find: ";
  cin >> key;
  cout << binarySearch(key, 0, n - 1);

  delete a;
  return 0;
}