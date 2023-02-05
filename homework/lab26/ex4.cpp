#include <iostream>
using namespace std;
#define MAX 50

void inputMatrix(double mat[][MAX], int &row, int &col)
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
}

int main()
{
    double mat[MAX][MAX];
    int row, col;
    inputMatrix(mat, row, col);

    // input vector by array
    double v[MAX], k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }

    double res[MAX];
    // mutiple matrix with array v
    for (int i = 0; i < row; i++)
    {
        res[i] = 0;
        for (int j = 0; j < col; j++)
        {
            res[i] += mat[i][j] * v[j];
        }
    }

    // print result
    for (int i = 0; i < row; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}