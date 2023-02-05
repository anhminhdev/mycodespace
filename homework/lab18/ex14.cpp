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

int maxArray(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int rowWithMax1s(int a[][100], int n)
{
    int b[100]; // mảng b chứa số lượng chữ số 1 của từng dòng trong mảng a
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
                count++;
        }
        b[i] = count;
    }

    int max_array_b = maxArray(b, n);
    if (max_array_b == 0)
        return -1;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] == max_array_b)
                return i;
        }
    }
}

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a, n);
    cout << "Matrix: " << endl;
    outputMatrix(a, n);

    int i = rowWithMax1s(a, n); // Tim dong co chua nhieu so 1 nhat
    if (i == -1)
        cout << "No row has 1" << endl;
    else
        cout << "Index of row with maximum number of 1s is " << i << endl;

    return 0;
}
