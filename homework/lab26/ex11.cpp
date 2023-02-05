/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

// ###INSERT CODE HERE -
using namespace std;

// Get first digit of a positive number
int firstDigit(int n)
{
  while (n >= 10)
  {
    n /= 10;
  }
  return n;
}

int main()
{
  int a[15];
  for (int i = 0; i < 10; i++)
  {
    cin >> a[i];
  }
  int count1 = 0, count4 = 0;
  for (int i = 0; i < 10; i++)
  {
    if (firstDigit(a[i]) == 1)
      count1++;
    else if (firstDigit(a[i]) == 4)
      count4++;
  }
  if (count1 == 3 && count4 == 1)
    cout << "TRUE";
  else
    cout << "FALSE";
  return 0;
}