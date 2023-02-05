#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10000

void input_string_array(char ch[])
{
    cin.getline(ch, 50);
}

void toggle(char ch[])
{
    for (int i = 0; i < strlen(ch); i++)
    {
        if (ch[i] >= 'a' && ch[i] <= 'z')
            ch[i] = toupper(ch[i]);
        else if (ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] = tolower(ch[i]);
    }
}

void output_string_array(char ch[])
{
    for (int i = 0; i < strlen(ch); i++)
        cout << ch[i];
}

int main()
{
    char ch[MAX];
    input_string_array(ch);
    toggle(ch);
    output_string_array(ch);
    return 0;
}