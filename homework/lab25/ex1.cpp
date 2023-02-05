/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;
int main()
{
  // ###INSERT CODE HERE -
  // input array a
  int na;
  cin >> na;
  int *a = new int[na];
  for (int i = 0; i < na; i++)
  {
    cin >> a[i];
  }

  int nb;
  cin >> nb;
  for (int i = 0; i < nb; i++)
  {
    int x;
    cin >> x;
    int flag = 0;
    for (int j = 0; j < na; j++)
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
  return 0;
}
