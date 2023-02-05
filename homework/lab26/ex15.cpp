#include <iostream>
using namespace std;

void printResult(int res[], int num)
{
  for (int i = num - 1; i >= 0; i--)
  {
    cout << res[i];
    if (i != 0)
      cout << " x ";
  }
  cout << endl;
}

int main()
{
  // Enter amount case
  int n;
  cin >> n;
  int a[100];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  // Traverse array a
  for (int i = 0; i < n; i++)
  {
    int res[100], num = 0;
    // Check each element in array a
    // How to convert loop while -> for??? :))
    int j = 2;
    while (a[i] != 1)
    {
      if (a[i] % j == 0)
      {
        res[num++] = j;
        a[i] /= j;
      }
      else
      {
        j++;
      }
    }
    printResult(res, num);
  }
  return 0;
}