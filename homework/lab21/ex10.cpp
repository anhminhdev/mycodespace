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
#include <string.h>
using namespace std;
#define MAX 300

void DemKyTu(char s[]);
// int myStrcmp(char s1[MAX], char s2[MAX]);
// int myStrlen(char s[], int k);

int main()
{
    char s[MAX];
    cin.getline(s, 299);

    DemKyTu(s);

    return 0;
}

// ###INSERT CODE HERE -

void DemKyTu(char s[])
{
    // Khai báo mảng s2 chứa các kí tự khác nhau riêng biệt của mảng s
    char s2[MAX];
    int len_s2 = 1;
    s2[0] = s[0];
    s2[len_s2] = '\0';
    // Duyệt chuỗi s
    for (int i = 1; s[i] != '\0'; i++)
    {
        int flag = 1;
        // Duyệt chuỗi s2
        for (int j = 0; s2[j] != '\0'; j++)
        {
            // Kiểm tra từng kí tự của chuỗi s có giống với các kí tự trong chuỗi s2 hay không
            if (s[i] == s2[j])
            {
                flag = 0;
                break;
            }
        }
        // Nếu kí tự s[i] hiện tại không trùng với các kí tự trong mảng s2 thì bỏ vào mảng s2
        if (flag == 1)
        {
            len_s2++;
            s2[len_s2] = '\0';
            s2[len_s2 - 1] = s[i];
        }
    }

    for (int i = 0; i < strlen(s2); i++)
    {
        int count = 0;
        for (int j = 0; j < strlen(s); j++)
        {
            if (s2[i] == s[j])
                count++;
        }
        cout << s2[i] << ": " << count << endl;
    }
}
