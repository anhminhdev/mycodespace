/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

// ###INSERT CODE HERE -

int SoSanhBangNhauTheoChuCai(char s[], char t[])
{
  if (strlen(s) != strlen(t))
    return 0;

  for (int i = 0; i < strlen(s); i++)
  {
    if (isdigit(s[i]) && !isdigit(t[i]))
    {
      return 0;
    }
    if ((!isdigit(s[i]) && !isalpha(s[i])) && (isdigit(t[i]) || isalpha(t[i])))
    {
      return 0;
    }
    if (isalpha(s[i]) && isalpha(t[i]))
    {
      if (toupper(s[i]) != toupper(t[i]))
      {
        return 0;
      }
    }
    if (isalpha(s[i]) && isalpha(t[i]))
    {
      if ((int)(tolower(s[i]) - toupper(t[i])) != 32)
      {
        return 0;
      }
    }
  }
  return 1;
}

int main()
{
  char s[256], t[256];
  cin.getline(s, 256);
  cin.getline(t, 256);
  cout << SoSanhBangNhauTheoChuCai(s, t); // chu cai giong nhau khac loai chu hoa va thuong, cung la so
  return 0;
}
