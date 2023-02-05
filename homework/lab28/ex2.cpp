#include <iostream>
using namespace std;
int n, m, a[1000000], x[1000000];
int binarySearch(int l, int r, int key)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;
    if (a[mid] == key)
      return mid;
    if (a[mid] > key)
      return binarySearch(l, mid - 1, key);
    return binarySearch(mid + 1, r, key);
  }
  return -1;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> x[i];
  for (int i = 0; i < m; i++)
    cout << binarySearch(0, n - 1, x[i]) << endl;
  return 0;
}
