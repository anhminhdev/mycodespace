#include <iostream>
using namespace std;
#define MAX 10 // Số lượng phần tử tối đa của mảng

// Nhập mảng
void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

// Xuất mảng
void outputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

void delete_numbers_sequence_array(int a[], int &n, int left, int right)
{
    // Duyệt mảng từ cuối lên đầu 
    for (int i = right; i >= left; i--)
    {
        for (int j = i; j < n; j++)
        {
            a[j] = a[j + 1];
        }
        n--;
    }
}

int main()
{
    int a[MAX], n, left, right;
    inputArray(a, n);
    cin >> left >> right;

    delete_numbers_sequence_array(a, n, left, right);

    outputArray(a, n);
    return 0;
}
