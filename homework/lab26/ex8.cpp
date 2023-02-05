#include <iostream>
#include <cmath>
using namespace std;

// n lẻ -> +
// n chẵn -> -

// Tìm chỉ số của phần tử nhỏ nhất trong mảng ở các vị trí n lẻ (a1: (i=0), a3: (i=2), a5: (i=4),...)
int indexMinArray(int a[], int n)
{
  int min = a[0], index = 0;
  for (int i = 2; i < n; i += 2)
  {
    if (a[i] < min)
    {
      min = a[i];
      index = i;
    }
  }
  return index;
}

// Tìm chỉ số của phần tử lớn nhất trong mảng ở các vị trí n chẵn (a2: (i=1), a4: (i=3), a6: (i=5),...)
int indexMaxArray(int a[], int n)
{
  int max = a[1], index = 1;
  for (int i = 3; i < n; i += 2)
  {
    if (a[i] > max)
    {
      max = a[i];
      index = i;
    }
  }
  return index;
}

int main()
{
  // Initial input array
  int a[100000], n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int idxMin = indexMinArray(a, n);
  int idxMax = indexMaxArray(a, n);
  if (a[idxMax] > a[idxMin])
  {
    swap(a[idxMax], a[idxMin]);
  }

  // Calculate sum and print result
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += pow(-1, i - 1) * a[i - 1];
  }
  cout << sum;
  return 0;
}