#include <iostream>
using namespace std;

void enterArray(int *a, int &n)
{
    cout << "Enter element numbers of array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void printArray(int *a, int n)
{
    cout << "The elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}

void deleteOddNumber(int *a, int &n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] % 2 != 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
        }
    }
}

// // test thử không để tham chiếu mảng a
// void realloc(int *a, int newSize, int oldSize)
// {
//     // Save data array a into array temp
//     int *temp = new int[oldSize];
//     for (int i = 0; i < oldSize; i++)
//     {
//         temp[i] = a[i];
//     }
//     // Release memory of array a then allocate new size
//     delete[] a;
//     a = new int[newSize];

// }

int main()
{
    int n;
    int *a = new int[n];

    enterArray(a, n);
    deleteOddNumber(a, n);
    // n = 5;
    printArray(a, n);
    delete[] a;
    return 0;
}