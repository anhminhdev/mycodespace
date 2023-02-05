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

int myStrlen(char s[], int k);           // Ham tra ve chieu dai chuoi s ke tu vi tri k
void myMemmove(char s[], int vt, int k); // Xoa k ky tu trong chuoi s, bat dau tu vi tri vt.
int myStrstr(char s[], char s1[]);       // Tim chuoi s1 trong chuoi s, neu tim thay tra ve vi tri s1[0] trong chuoi s, khong tin thay tra ve -1
void Chuanhoa(char s[]);

int main()
{
    char s[MAX];
    cin.getline(s, 299); // Nhap chuoi s
    Chuanhoa(s);
    cout << s << endl;
    return 0;
}

// ###INSERT CODE HERE -
int myStrlen(char s[], int k)
{
    int count = 0;
    for (int i = k; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void Chuanhoa(char s[])
{
    int length = myStrlen(s, 0);
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
    // Chuyển đổi tất cả kí tự của chuỗi thành kí tự thường
    for (int i = 0; i < length; i++)
    {
        s[i] = tolower(s[i]);
    }
    // Viết hoa các kí tự đầu của mỗi từ
    s[0] = toupper(s[0]);
    for (int i = 1; i < length; i++)
    {
        if (s[i] != ' ' && s[i - 1] == ' ')
            s[i] = toupper(s[i]);
    }
}