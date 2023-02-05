/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAX 16

void Nhapmang(int a[][MAX], int &n);
void Xuatmang(int a[][MAX], int n);

// ###INSERT CODE HERE -

// Tìm số fibonancci thứ n
int fibonancci(int n)
{
    int a = 0, b = 1;
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int recursiveFibonancci(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return recursiveFibonancci(n - 2) + recursiveFibonancci(n - 1);
    }
}

void Nhapmang(int a[][MAX], int &n)
{
    cin >> n;
}

void Xuatmang(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << recursiveFibonancci(i + j + 1) << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n, a[MAX][MAX];
    Nhapmang(a, n);
    Xuatmang(a, n);

    return 0;
}