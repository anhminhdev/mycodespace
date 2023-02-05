/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

// ###INSERT CODE HERE -
#include <iostream>
#include <cmath>
using namespace std;
#define MAXR 100
#define MAXC 100

void NhapMaTran(int a[][MAXC], int &n)
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

double TinhDinhThuc(int matrix[][MAXC], int n)
{
    int det = 0;
    int submatrix[MAXC][MAXC];
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * TinhDinhThuc(submatrix, n - 1));
        }
    }
    return det;
}

int main()
{
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout << TinhDinhThuc(a, n);
    return 0;
}
