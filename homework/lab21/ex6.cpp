/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
class
string
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

// ###INSERT CODE HERE -

// Chèn 1 kí tự khoảng trắng
void insertSpace(char s[], int pos, int &length)
{
    length++;
    s[length] = '\0';
    for (int i = length - 1; i > pos; i--)
    {
        s[i] = s[i - 1];
    }
    s[pos] = ' ';
}

// Xóa 1 kí tự khoảng trắng
void deleteSpace(char s[], int pos, int &length)
{
    for (int i = pos; i < length - 1; i++)
    {
        s[i] = s[i + 1];
    }
    s[length - 1] = '\0';
}

void Chuanhoa(char s[])
{
    int length = strlen(s);
    // Xóa hết kí tự khoảng trắng đầu chuỗi
    while (isspace(s[0]))
    {
        for (int i = 0; i < length - 1; i++)
        {
            s[i] = s[i + 1];
        }
        s[length - 1] = '\0';
    }
    // Xóa hết kí tự khoảng trắng cuối chuỗi
    int j = length - 1;
    while (isspace(s[j]))
    {
        j--;
    }
    if (j < length - 1)
    {
        s[j + 1] = '\0';
        length = j + 1;
    }
    // Nếu bên trong chuỗi có nhiều kí tự khoảng trắng liên tiếp nhau thì xóa còn 1
    for (int i = 0; i < length - 1; i++)
    {
        if (isspace(s[i]) && isspace(s[i + 1]))
        {
            for (int j = i; j < length - 1; j++)
            {
                s[j] = s[j + 1];
            }
            i--;
            length--;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '.' && s[i - 1] == ' ')
        {
            deleteSpace(s, i - 1, length);
            i--;
        }
        if (s[i] == '.' && s[i + 1] != ' ')
        {
            insertSpace(s, i + 1, length);
        }
    }
}

int main()
{
    char s[MAX];
    cin.getline(s, 299);

    char s1[MAX];
    strcpy(s1, s);
    Chuanhoa(s1);
    cout << s << endl
         << s1 << endl;
    return 0;
}
