/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void inputArray(int a[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
}

void outputArray(int a[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void vertical_invert(int a[][100], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col / 2; j++)
        {
            swap(a[i][j], a[i][col - 1 - j]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a[100][100];

    inputArray(a, n, m);

    vertical_invert(a, n, m);

    outputArray(a, n, m);

    return 0;
}
