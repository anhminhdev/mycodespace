/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

void inputMatrix(int a[][100], int &n);

void outputMatrix(int a[][100], int n);

/* Ham kiem tra ma tran cheo
 La ma tran cheo neu moi phan tu nam ben ngoai duong cheo chinh deu bang 0*/
int isDiagonalMatrix(int a[][100], int n);

/*Ham kiem tra ma tran don vi
La ma tran don vi neu moi phan tu tren duong cheo chinh bang 1
va tat ca cac phan tu khac deu bang 0
Ma tran don vi cung la truong hop dac biet cua ma tran cheo*/
int isIdentityMatrix(int a[][100], int n);

int main()
{
    int a[100][100];
    int n;
    inputMatrix(a, n);
    cout << "Matrix: " << endl;
    outputMatrix(a, n);

    // ###INSERT CODE HERE -
    if (isIdentityMatrix(a, n) == 1)
        cout << "a is called a identity matrix";
    else if (isDiagonalMatrix(a, n) == 1)
        cout << "a is called a diagonal matrix";
}

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

int isDiagonalMatrix(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && a[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int isIdentityMatrix(int a[][100], int n)
{
    if (isDiagonalMatrix(a, n) == 0)
        return 0;
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j && a[i][j] != 1)
                    return 0;
            }
        }
        return 1;
    }
}
