/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include <cstring>

using namespace std;

// ###INSERT CODE HERE -
bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z');
}

bool SoSanhBangNhau(char s[], char t[])
{
    if (strlen(s) != strlen(t))
        return false;

    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (isAlpha(s[i]) && !isAlpha(t[i]))
            return false;
        if (isAlpha(s[i]) && isAlpha(t[i]))
        {
            if (tolower(s[i]) != tolower(t[i]))
                return false;
        }
        if (!isAlpha(s[i]) && isAlpha(t[i]))
            return false;
    }
    return true;
}

int main()
{
    char s[256], t[256];
    cin.getline(s, 256);
    cin.getline(t, 256);
    cout << SoSanhBangNhau(s, t);

    return 0;
}
