
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;
#define MIN -1000
#define MAX 1000

int isTotalOven(int *a, int n) // or (int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            return 0;
    return 1;
}
int isValidValue(int *a, int n) // or (int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] < 2 * MIN || a[i] > 2 * MAX)
            return 0;
    return 1;
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    // ###INSERT CODE HERE -
    srand(time(0));

    int n;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = (2 * MIN) + rand() % ((2 * MAX) - (2 * MIN) + 1);
    }

    printArray(a, n);

    if (isTotalOven(a, n) == 1)
        cout << "Mang toan so chan" << endl;
    if (isValidValue(a, n) == 1)
        cout << "Mang chua cac gia tri nam trong khoang [" << 2 * MIN << "," << 2 * MAX << "]";

    return 0;
}
