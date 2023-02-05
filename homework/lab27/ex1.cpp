/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// ###INSERT CODE HERE -
void removeSpaceHead(char s[])
{
  int start = 0, len = strlen(s);
  while (start < len && s[start] == ' ')
  {
    start++;
  }
  // Case all character in array as space
  if (start == len)
  {
    s[0] = '\0';
    return;
  }
  // Reset character array
  int i = 0;
  while (start < len)
  {
    s[i++] = s[start++];
  }
  s[i] = '\0';
}

void removeSpaceLast(char s[])
{
  int i = strlen(s) - 1;
  while (s[i] == ' ')
  {
    i--;
  }
  s[i + 1] = '\0';
}

int main()
{
  char s[100], res[1000];
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 1; i <= n; i++)
  {
    cin.getline(s, sizeof(s));
    removeSpaceHead(s);
    removeSpaceLast(s);
    strcat(res, s);
    if (i < n)
    {
      strcat(res, "-");
    }
  }
  cout << res;
  return 0;
}