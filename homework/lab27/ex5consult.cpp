#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  getline(cin, s);
  int len = s.length();
  for (int i = 0; i < len; i++)
  {
    for (int j = i + 1; j <= len; j++)
    {
      string sub = s.substr(i, j - i);
      cout << sub << endl;
    }
  }
  return 0;
}
