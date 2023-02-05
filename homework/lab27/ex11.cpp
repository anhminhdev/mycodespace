#include <bits/stdc++.h>
using namespace std;

bool isUpperCase(char c)
{
  return (c > 'A' && c < 'Z');
}

int main()
{
  string s;
  getline(cin, s);

  char word[100][100];
  int j = 0, k = 0; // row, col of two dimensional array
  int i = 0;        // index of input string s
  while (s[i])
  {
    if (!isspace(s[i]))
    {
      word[j][k++] = s[i];
    }
    else
    {
      word[j][k] = '\0';
      j++;
      k = 0;
    }
    i++;
  }
  word[j][k] = '\0';
  int amountWord = j + 1;

  for (int j = 0; j < amountWord; j++)
  {
    k = strlen(word[j]) - 1;
    if (!isalpha(word[j][k]))
    {
      word[j][k] = '\0';
    }
  }

  // assign reset col equal 0
  k = 0;
  for (j = 0; j < amountWord; j++)
  {
    if (isUpperCase(word[j][k]) && isUpperCase(word[j + 1][k]) && isUpperCase(word[j + 2][k]))
    {
      cout << word[j] << ' ' << word[j + 1] << ' ' << word[j + 2] << endl;
      j += 2;
    }
    if (isUpperCase(word[j][k]) && isUpperCase(word[j + 1][k]))
    {
      cout << word[j] << ' ' << word[j + 1] << endl;
    }
  }
  return 0;
}