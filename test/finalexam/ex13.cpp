/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/
#include <iostream>
#include <cstring>
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

void transformString(char s1[], char s2[], char x)
{
  cin >> x;
  strcpy(s2, s1);
  removeHeadSpace(s2);
  removeLastSpace(s2);
  removeMidSpace(s2);
  // chuyen het thanh ki tu thuong
  for (int i = 1; i < strlen(s2); i++)
  {
    s2[i] = tolower(s2[i]);
  }
  s2[0] = toupper(s2[0]);
  // solve
  for (int i = 1; i < strlen(s2); i++)
  {
    if (s2[i - 1] == ' ' && isalpha(s2[i]))
    {
      s2[i] = toupper(s2[i]);
    }
    if (!isdigit(s2[i]) && !isalpha(s2[i]) && s2[i] != ' ')
    {
      s2[i] = x;
    }
  }
}

int main()
{
  char s1[200], s2[200];
  char x;
  cout << "Nhap chuoi = ";
  cin.getline(s1, 199);
  transformString(s1, s2, x);
  cout << "\ns1=" << s1 << endl;
  cout << "s2=" << s2;

  return 0;
}
