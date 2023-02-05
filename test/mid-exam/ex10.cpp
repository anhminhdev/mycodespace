#include <iostream>
using namespace std;

void inputMatrix(double a[][100], int &row, int &col)
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
}

int main()
{
    double a[100][100];
    int row, col;
    inputMatrix(a, row, col);

    // Duyệt từng cột
    for (int j = 0; j < col; j++)
    {
        // Gán phần tử ở dòng đầu tiên, cột j hiện tại cho biến max
        double max = a[0][j];
        // Duyệt từng dòng
        for (int i = 1; i < row; i++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
        cout << "Gia tri lon nhat tren cot " << j << " la: " << max << endl;
    }
    return 0;
}