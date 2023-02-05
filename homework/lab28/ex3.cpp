/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
void inputArray(int *&a, int &n)
{
  cin >> n;
  a = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}

int binarySearch(int *a, int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;
    if (a[mid] == x)
    {
      while (a[mid] == x)
      {
        mid++;
        if (a[mid] != x)
        {
          return mid - 1;
        }
      }
    }
    if (a[mid] > x)
    {
      return binarySearch(a, l, mid - 1, x);
    }
    else // a[mid] < x
      return binarySearch(a, mid + 1, r, x);
  }
  return -1;
}

int binarySearch2(int *a, int n, int x)
{
  int l = 0, r = n - 1;
  return binarySearch(a, l, r, x);
}

int main()
{
  int n, *a = NULL;
  inputArray(a, n); // Luu y van de tham chieu cho con tro a va n

  // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
  int x;
  while (1)
  {
    cin >> x;
    if (x == -1)
      break;
    cout << binarySearch2(a, n, x) << endl;
  }

  return 0;
}
