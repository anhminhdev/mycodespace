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
void removeHeadSpace(char s[])
{
  int start = 0, len = strlen(s);
  while (start < len && s[start] == ' ')
  {
    start++;
  }
  if (start == len)
  {
    s[0] = '\0';
    return;
  }
  int i = 0;
  while (start < len)
  {
    s[i++] = s[start++];
  }
  s[i] = '\0';
}

void removeLastSpace(char s[])
{
  int i = strlen(s) - 1;
  while (s[i] == ' ')
  {
    i--;
  }
  s[i + 1] = '\0';
}

// If many consecutive spaces, delete only 1 left
void removeMidSpace(char s[])
{
  int len = strlen(s);
  for (int i = len - 1; i > 0; i--)
  {
    if (s[i] == ' ' && s[i - 1] == ' ')
    {
      int j = i;
      for (; j < len - 1; j++)
      {
        s[j] = s[j + 1];
      }
      len--;
    }
  }
  s[len] = '\0';
}

void lowercaseAllCharacter(char s[])
{
  for (int i = 0; i < strlen(s); i++)
  {
    s[i] = tolower(s[i]);
  }
}

int main()
{
  char s[500];
  cin.getline(s, sizeof(s));
  removeHeadSpace(s);
  removeLastSpace(s);
  removeMidSpace(s);
  lowercaseAllCharacter(s);
  s[0] = toupper(s[0]);
  for (int i = 1; i < strlen(s); i++)
  {
    if (s[i] == ' ' && s[i + 1] != ' ')
    {
      s[i + 1] = toupper(s[i + 1]);
    }
  }
  cout << s;
  return 0;
}