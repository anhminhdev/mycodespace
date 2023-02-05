/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
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

void findElements(int *a, int n, int &m)
{
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
      if (a[j] == x)
      {
        cout << j << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      cout << -1 << endl;
  }
}

int main()
{
  int n, m;
  int *a = NULL;
  inputArray(a, n);
  findElements(a, n, m);

  return 0;
}
