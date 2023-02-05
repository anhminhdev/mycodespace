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

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
    char s[MAX], s1[MAX];
    cin.getline(s, 299);
    cin.getline(s1, 299);
    int k;
    cin >> k;
    if (k < 0 || k > myStrlen(s, 0))
        cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
    else
    {
        // ###INSERT CODE HERE -
        ChenChuoiTaiVitriK(s, s1, k);
    }
}

// Hàm trả về chiều dài chuỗi con của s kể từ vị trí k đến cuối chuỗi s
int myStrlen(char s[], int k)
{
    int count = 0;
    for (int i = k; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
    int len_s = myStrlen(s, 0);
    int len_s1 = myStrlen(s1, 0);
    char res[MAX + MAX];
    // Vòng lặp để duyệt qua từng kí tự trong chuỗi s và chèn chúng vào mảng result tới khi tìm đến vị trí k
    int i = 0;
    for (; i < k; i++)
    {
        res[i] = s[i];
    }
    // Vòng lặp để duyệt qua từng kí tự trong chuỗi s1 và chèn chúng vào mảng result tới khi hết chuỗi s1
    for (int j = 0; j < len_s1; j++)
    {
        res[i++] = s1[j];
    }
    res[i++] = ' ';
    // Vòng lặp để duyệt qua các kí tự còn lại trong chuỗi s và chèn chúng vào mảng result
    for (int j = k; s[j] != '\0'; j++)
    {
        res[i++] = s[j];
    }
    res[i] = '\0';
    cout << res;
}
