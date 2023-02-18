/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
void inputArray(int a[], int &n)
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
}
bool isPrime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i <= n / 2; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

void insert(int a[], int &n, int pos, int val)
{
  n++;
  for (int i = n - 1; i > pos; i--)
  {
    a[i] = a[i - 1];
  }
  a[pos] = val;
}
void printArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
}
void insertIntoArray(int a[], int &n)
{
  for (int i = 0; i < n; i++)
  {
    if (isPrime(a[i]))
    {
      insert(a, n, i, a[i] + 1);
      i++;
      // printArray(a, n);
      // cout << endl;
    }
  }
}

int main()
{
  int a[100], n;
  inputArray(a, n);
  insertIntoArray(a, n);
  printArray(a, n);
  return 0;
}
