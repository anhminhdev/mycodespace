#include <iostream>
using namespace std;
#define MAX 100

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

bool isFrobeniusMatrix(double mat[][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = 0; j < col; j++)
        {
            if (i == j && mat[i][j] != 1)
                return false;
            else if (i > j && mat[i][j] != 0)
            {
                count++;
                if (count > 1)
                    return false;
            }
            else if (i < j && mat[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{
    double mat[MAX][MAX];
    int row, col;
    inputMatrix(mat, row, col);
    if (isFrobeniusMatrix(mat, row, col))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}