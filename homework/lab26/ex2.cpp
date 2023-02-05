/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAX 1000
void input(unsigned int arr[][MAX], unsigned int &m, unsigned int &n);
unsigned int countPrimeInAB(unsigned int arr[][MAX], unsigned int m, unsigned int n, unsigned int a, unsigned int b);

// ###INSERT CODE HERE -
bool isPrime(int x)
{
    if (x == 0 || x == 1)
        return false;
    else
    {
        for (int i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
}

void input(unsigned int arr[][MAX], unsigned int &m, unsigned int &n)
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

unsigned int countPrimeInAB(unsigned int arr[][MAX], unsigned int m, unsigned int n, unsigned int a, unsigned int b)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isPrime(arr[i][j]) && (arr[i][j] >= a && arr[i][j] <= b))
                count++;
        }
    }
    return count;
}

int main()
{
    unsigned int a;
    unsigned int b;
    unsigned int arr[MAX][MAX];
    unsigned int m;
    unsigned int n;

    cin >> a >> b;
    input(arr, m, n);
    unsigned int res = countPrimeInAB(arr, m, n, a, b);
    cout << res;

    return 0;
}