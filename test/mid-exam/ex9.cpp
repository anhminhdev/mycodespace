/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
void inputMatrix(int a[][100], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void outputMatrix(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void sumOfOneRow(int a[][100], int n, int b[])
{
    for (int i = 0; i < n; i++)
    {
        int sum = a[i][0];
        for (int j = 1; j < n; j++)
        {
            sum += a[i][j];
        }
        b[i] = sum;
    }
}

int maxArrayb(int b[], int n)
{
    int max = b[0];
    for (int i = 1; i < n; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
        }
    }
    return max;
}

int rowWithMaximumSum(int a[][100], int n)
{
    int b[100];
    sumOfOneRow(a, n, b);
    int max = maxArrayb(b, n);
    for (int i = 0; i < n; i++)
    {
        if (b[i] == max)
            return i;
    }
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a, n);
    cout << "Matrix: " << endl;
    outputMatrix(a, n);

    // Tim dong co tong lon nhat trong ma tran
    cout << "Row " << rowWithMaximumSum(a, n) << " has max sum " << endl;

    return 0;
}
