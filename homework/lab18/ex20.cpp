#include <iostream>
#include <cstring>
using namespace std;

void input_string(char s[])
{
    cin.getline(s, 256);
}

// Hàm kiểm tra chữ cái viết thường
bool isLowerAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int count_special_words(char s[])
{
    int length = strlen(s);
    int count(0);
    // Nếu kí tự đầu tiên là chữ cái viết thường thì đếm++
    if (isLowerAlpha(s[0]))
    {
        count++;
        for (int i = 1; s[i] != ' ' && i < length; i++)
        {
            if (!isLowerAlpha(s[i]))
            {
                count--;
                break;
            }
        }
    }

    // Duyệt từ kí tự thứ 2 đến cuối chuỗi
    for (int i = 1; i < length; i++)
    {
        // Nếu kí tự tại chỉ số i khác khoảng trắng và kí tự trước nó là khoảng trắng
        if (s[i] != ' ' && s[i - 1] == ' ')
        {
            count++;
            int j = i;
            // Vòng lặp để duyệt kiểm tra hết các kí tự của từ đó
            for (; s[j] != ' ' && j < length; j++)
            {
                // Nếu có kí tự nào không phải viết thường
                if (!isLowerAlpha(s[j]))
                {
                    count--;
                    break;
                }
            }
            // Cho chỉ số của i nhảy lên đến chỉ số j
            i = j;
        }
    }
    return count;
}

int main()
{
    char s[256];
    input_string(s);
    cout << count_special_words(s);
    return 0;
}