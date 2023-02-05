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

int rowWithAll0sOr1s(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        int all_zeros = true;
        int all_ones = true;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
                all_zeros = false;
            if (a[i][j] != 1)
                all_ones = false;
        }
        if (all_ones || all_zeros)
            return i;
    }
    return -1;
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a, n);
    cout << "Matrix: " << endl;
    outputMatrix(a, n);

    int j = rowWithAll0sOr1s(a, n); // Tim dong chua toan so 0 hoac toan so 1, tra ve dong dau tien tim thay hoac -1 neu khong co
    if (j == -1)
        cout << "No row has all 1s or all 0s" << endl;
    else
        cout << "Index of row with all 1s or 0s is " << j << endl;

    return 0;
}
