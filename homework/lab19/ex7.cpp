#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int length = s.length();
    // Erase space character at head string
    // Loop never stop unless character s[0] is not space character
    while (isspace(s[0]))
    {
        s.erase(0, 1);
    }
    // Erase space character at end string
    while (isspace(s[length - 1]))
    {
        s.erase(length - 1, 1);
    }
    // Erase space character inside string
    for (int i = 0; i < length; i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            s.erase(i, 1);
            i--;
        }
    }
    cout << s;
    return 0;
}