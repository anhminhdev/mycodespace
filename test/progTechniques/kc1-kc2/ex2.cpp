#include <iostream>
using namespace std;

// Count number odd digits by recursion
int numberOddDigits(int n)
{
    if (n == 0)
        return 0;
    if ((n % 10) % 2 != 0)
        return 1 + numberOddDigits(n / 10);
    return numberOddDigits(n / 10);
}

// Tail recursion
int tailRecursion(int n, int cnt = 0)
{
    if (n == 0)
        return cnt;
    if ((n % 10) % 2 != 0)
        return tailRecursion(n / 10, cnt + 1);
    else
        return tailRecursion(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << tailRecursion(n);
    return 0;
}