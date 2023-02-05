/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
string
strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
    char s1[MAX], s2[MAX];
    cin.getline(s1, 254);
    cin.getline(s2, 254);
    bool kt = myStrcat(s1, s2);

    // ###INSERT CODE HERE -
    if (kt == false)
        cout << "Khong noi duoc. Khong du bo nho.";
    else
    {
        cout << s1;
    }
}

int myStrlen(char s[])
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

bool myStrcat(char s1[], char s2[])
{
    int length_s1 = myStrlen(s1);
    int length_s2 = myStrlen(s2);
    if (length_s1 + length_s2 > MAX)
        return false;
    else
    {
        for (int i = 0; i < length_s2; i++)
        {
            s1[length_s1] = s2[i];
            length_s1++;
        }
        s1[length_s1] = '\0';
        return true;
    }
}