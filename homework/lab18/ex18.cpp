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

bool specialCharacter(char ch)
{
    return (!isDigit(ch) && !isAlpha(ch));
}

bool SoSanhBangNhauTheoSo(char s[], char t[])
{
    // Nếu độ dài 2 chuỗi khác nhau thì 2 chuỗi không bằng nhau
    if (strlen(s) != strlen(t))
        return false;

    // Duyệt từng phần tử chuỗi s so sánh với chuỗi t
    for (int i = 0; i < strlen(s); i++)
    {
        if (isDigit(s[i]) && !isDigit(t[i]))
            return false;
        if (isDigit(s[i]) && isDigit(t[i]) && s[i] != t[i])
            return false;
        if (isAlpha(s[i]) && !isAlpha(t[i]))
            return false;
        if (specialCharacter(s[i]) && !specialCharacter(t[i]))
            return false;
    }
    return true;
}

int main()
{
    char s[256], t[256];
    cin.getline(s, 256);
    cin.getline(t, 256);
    cout << SoSanhBangNhauTheoSo(s, t); // so giong nhau, cung la chu cai

    return 0;
}
