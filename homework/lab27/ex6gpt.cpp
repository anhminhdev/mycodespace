#include <iostream>
#include <string.h>

using namespace std;

// Function to split the input string into separate words
void split(char str[], char words[][20], int &wordCount)
{
  int i, j, k;
  i = j = k = 0;

  // Split the input string into separate words
  while (str[i])
  {
    if (str[i] != ' ')
    {
      words[j][k++] = str[i];
    }
    else
    {
      words[j][k] = '\0';
      j++;
      k = 0;
    }
    i++;
  }
  words[j][k] = '\0';
  wordCount = j + 1;
}

int main()
{
  char str[100];
  char words[20][20];
  int wordCount, i, j, flag;
  int count[20];

  cout << "Nhap chuoi: ";
  cin.getline(str, 100);

  // Check if the input string is empty
  if (strlen(str) == 0)
  {
    cout << "Chuoi rong." << endl;
    return 0;
  }

  split(str, words, wordCount);

  // Initialize the count array to 0
  for (i = 0; i < wordCount; i++)
  {
    count[i] = 0;
  }

  // Count the number of times each word appears in the string
  for (i = 0; i < wordCount; i++)
  {
    flag = 0;
    for (j = 0; j < i; j++)
    {
      if (strcmp(words[i], words[j]) == 0)
      {
        count[j]++;
        flag = 1;
        break;
      }
    }
    if (!flag)
    {
      count[i] = 1;
    }
  }

  // Print the count of each word
  for (i = 0; i < wordCount; i++)
  {
    cout << words[i] << ": " << count[i] << endl;
  }

  return 0;
}
