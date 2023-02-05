/*
exam: n = 30
30 divide 2 = 15 residual 0
15 divide 2 = 7 residual 1
7 divide 2 = 3 residual 1
3 divide 2 = 1 residual 1
1 divide 2 = 0(stop) residual 1
30 ==> 11110
*/

#include <iostream>
using namespace std;

// Binary representation of integer
int integerBinary(int n)
{
    // Cách này sai nếu n là số cực kỳ lớn thì dãy số nhị phân có thể nhiều hơn 100 phần tử
    int r[100], i = 0;
    while (true)
    {
        r[i++] = n % 2;
        if (n / 2 == 0)
            break;
        n /= 2;
    }
    i--;
    int result = 0;
    while (i >= 0)
    {
        result = result * 10 + r[i];
        i--;
    }
    return result;
}

void integerBinaryRecursion(int n)
{
    if (n == 0)
    {
        return;
    }
    integerBinaryRecursion(n / 2);
    cout << n % 2;
}

int main()
{
    int n;
    cout << "Enter n = ";
    cin >> n;
    cout << "Binary representation of " << n << ": " << integerBinary(n) << endl;
    integerBinaryRecursion(n);
    return 0;
}