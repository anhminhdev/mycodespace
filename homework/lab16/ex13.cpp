#include <iostream>
using namespace std;
#define MAX 100

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void outputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

void delete_all_elements_value_x(int a[], int &n, int x)
{
    // Duyệt mảng a từ phần tử cuối lên phần tử đầu
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == x)
        {
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];
            n--;
        }
    }
}

int main()
{
    int a[MAX], n;
    inputArray(a, n);
    int x;
    cin >> x;
    delete_all_elements_value_x(a, n, x);
    outputArray(a, n);
    return 0;
}