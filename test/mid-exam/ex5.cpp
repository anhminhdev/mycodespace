#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void insertOneElement(int a[], int &n, int pos)
{
    n++;
    for (int i = n - 1; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = 0;
}

void add_number_0_behind_primeNumber(int a[], int &n, int b[], int &nb)
{
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            insertOneElement(a, n, i + 1);
            // array b is contain index position inserted
            b[nb++] = i + 1;
        }
    }
}

int main()
{
    int a[100], b[100], n, nb = 0;
    inputArray(a, n);
    add_number_0_behind_primeNumber(a, n, b, nb);
    printArray(a, n);
    printArray(b, nb);
    return 0;
}
