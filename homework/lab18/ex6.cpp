/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

// ###INSERT CODE HERE -

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void outputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

bool isPow(int x)
{
    for (int i = 0; pow(2, i) <= x; i++)
    {
        if (pow(2, i) == x)
            return true;
    }
    return false;
}

bool isTotalPow(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isPow(a[i]) == false)
            return false;
    }
    return true;
}

int maxPow(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main()
{
    int n, a[100];
    inputArray(a, n);
    cout << "Array:" << endl;
    outputArray(a, n);
    cout << endl;

    if (isTotalPow(a, n) == 1)
    {
        cout << "Mang toan so luy thua cua co so 2" << endl;
        cout << "So luy thua cua co so 2 lon nhat: " << maxPow(a, n);
    }
    else
        cout << "Mang khong phai chua toan cac so luy thua cua co so 2";

    return 0;
}
