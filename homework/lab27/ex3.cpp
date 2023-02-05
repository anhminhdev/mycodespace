/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
using namespace std;

// ###INSERT CODE HERE -

void listWord(char str[])
{
  char *token = strtok(str, " ");
  while (token != NULL)
  {
    cout << token << endl;
    token = strtok(NULL, " ");
  }
}

int main()
{

  char str[100];
  cin.getline(str, 100);
  listWord(str);

  return 0;
}
