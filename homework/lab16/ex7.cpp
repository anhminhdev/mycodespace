#include <iostream>
using namespace std;
#define MAX 100

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

bool arrayAscending(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= a[i + 1])
            return false;
    }
    return true;
}

bool arrayDescending(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] <= a[i + 1])
            return false;
    }
    return true;
}

int main()
{
    int a[MAX], n;
    inputArray(a, n);

    if (arrayAscending(a, n) == true)
        cout << "Mang tang dan";
    else if (arrayDescending(a, n) == true)
        cout << "Mang giam dan";
    else
        cout << "Mang khong tang, khong giam";
    return 0;
}
