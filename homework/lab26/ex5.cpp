#include <iostream>
#include <cmath>
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

    double res = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res += pow(mat[i][j], 2);
        }
    }

    cout << scientific << sqrt(res);
    return 0;
}