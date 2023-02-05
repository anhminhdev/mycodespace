
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

// ###INSERT CODE HERE -

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << "\n";
}

void delete_one_element(int a[], int &n, int pos)
{
    for (int i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

void removeDups(int a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                delete_one_element(a, n, j);
                i--;
                j--;
            }
            if (i == -1)
                i = 0;
        }
    }

    printArray(a, n);
}
int main()
{
    int a[100], n;
    inputArray(a, n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
     *  khong xuat nhung gia tri bi lap lai/bi trung
     */

    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
