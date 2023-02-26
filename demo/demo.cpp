#include <iostream>
using namespace std;

int main()
{
  for (int i = 0; i < 3; i++)
  {
    cout << i;
  }
  for (int i = 0; i < 3; ++i)
  {
    cout << i;
  }
  // chốt lại là i++ hay ++i trong vòng for đều như nhau
  return 0;
}