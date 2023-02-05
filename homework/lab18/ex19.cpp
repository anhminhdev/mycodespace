
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <cstring>
using namespace std;

// ###INSERT CODE HERE -

bool isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

int countWords(char s[])
{
    int count(0);
    if (isAlpha(s[0]))
        count++;
    for (int i = 1; i < strlen(s); i++)
    {
        if (isAlpha(s[i]) == true && s[i - 1] == ' ')
            count++;
    }
    return count;
}

int main()
{

    char s[256];
    cin.getline(s, 256);

    cout << countWords(s) << endl;
    return 0;
}
