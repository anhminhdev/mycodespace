#include <iostream>
using namespace std;
#define MAX 1000

void inputArray(int a[], int na)
{
    for (int i = 0; i < na; i++)
    {
        cin >> a[i];
    }
}

bool check(int a[], int na, int b[], int nb, int i)
{
    for (int j = 0; j <= nb; j++)
    {
        if (a[i] == b[j])
            return false;
    }
    return true;
}

void handle(int a[], int na, int b[], int nb)
{
    for (int i = 0; i < na; i++)
    {
        if (check(a, na, b, nb, i) == true)
            cout << a[i] << ' ';
    }
}

int main()
{
    int a[MAX], b[MAX], na, nb;
    cin >> na >> nb;
    inputArray(a, na);
    inputArray(b, nb);

    handle(a, na, b, nb);
    return 0;
}
