#include <iostream>
using namespace std;
#define MAX 100000

int GCD(int a, int b)
{
  if (b == 0)
    return a;
  return GCD(b, a % b);
}

int main()
{
  int n;
  cin >> n;
  int a[MAX];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  // 12 15 18
  // 6 ->remove 15
  int max_gcd = 0;
  int index_to_remove = 0;
  for (int i = 0; i < n; i++)
  {
    int current_gcd = 0;
    for (int j = 0; j < n; j++)
    {
      if (j == i)
        continue;
      current_gcd = GCD(current_gcd, a[j]);
    }
    if (current_gcd > max_gcd)
    {
      max_gcd = current_gcd;
      index_to_remove = i;
    }
  }

  cout << index_to_remove + 1 << ' ' << max_gcd;
  return 0;
}