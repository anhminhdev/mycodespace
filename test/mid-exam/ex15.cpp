#include <iostream>
#include <string>
using namespace std;

string inputString(string &str)
{
    getline(cin, str);
    return str;
}

int countSpecialWords(string str)
{
    int count = 0;
    int length = str.length();

    int k = 1;
    if (!isspace(str[0]) && !isdigit(str[0]))
    {
        count++;
        for (; str[k] != ' ' && k < length; k++)
        {
            if (isdigit(str[k]))
            {
                count--;
                break;
            }
        }
    }
    for (int i = k; i < length; i++)
    {
        if (!isspace(str[i]) && !isdigit(str[i]) && str[i - 1] == ' ')
        {
            count++;
            int j = i;
            for (; str[j] != ' ' && j < length; j++)
            {
                if (isdigit(str[j]))
                {
                    count--;
                    break;
                }
            }
            i = j;
        }
    }

    return count;
}

int main()
{
    string str;
    inputString(str);
    cout << countSpecialWords(str);
    return 0;
}