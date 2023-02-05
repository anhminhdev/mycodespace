/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

// ###INSERT CODE HERE -
using namespace std;
const int MAX = 1000;

void sortArrayAscending(int x[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (x[i] > x[j])
      {
        swap(x[i], x[j]);
      }
    }
  }
}
int main()
{
  int a[MAX], b[MAX], c[MAX + MAX];
  int na, nb, nc = 0;
  cin >> na >> nb;
  // Input array a
  for (int i = 0; i < na; i++)
  {
    cin >> a[i];
  }
  // Input array b
  for (int i = 0; i < nb; i++)
  {
    cin >> b[i];
  }
  // Pour array a into array c
  for (int i = 0; i < na; i++)
  {
    c[nc++] = a[i];
  }
  // Pour array b into array c
  for (int i = 0; i < nb; i++)
  {
    c[nc++] = b[i];
  }
  sortArrayAscending(c, nc);
  // Print array c result
  for (int i = 0; i < nc; i++)
  {
    cout << c[i] << endl;
  }
  return 0;
}