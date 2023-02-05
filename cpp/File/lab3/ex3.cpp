#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100

void read_file(ifstream &filein, int a[], int &n)
{
    char x;
    while (!filein.eof()) // filein.eof() == false
    {
        filein >> a[n];
        n++;
        // Read comma to variable x
        filein >> x;
    }
}

void output_array(int a[], int n)
{
    cout << "Integers sequence is:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

// Eculids algorithm
int GCD_two_numbers(int a, int b)
{
    if (b == 0)
        return a;
    // replace a with b, replace b with a % b
    return GCD_two_numbers(b, a % b);
}

// Find greatest common divisor of all elements in array
int GCD_all_elements_array(int a[], int n)
{
    int result = a[0];
    for (int i = 1; i < n; i++)
    {
        result = GCD_two_numbers(result, a[i]);
    }
    return result;
}

int LCM_two_numbers(int x, int y)
{
    return (x * y) / GCD_two_numbers(x, y);
}

int LCM_all_elements_array(int a[], int n)
{
    int result = a[0];
    for (int i = 1; i < n; i++)
    {
        result = LCM_two_numbers(result, a[i]);
    }
    return result;
}

int main()
{
    int a[MAX];
    int n(0);
    // Read file
    ifstream filein;
    filein.open("input.txt", ios_base::in);

    read_file(filein, a, n);

    filein.close();

    // Write file
    ofstream fileout;

    fileout.open("GCD_array.txt", ios_base::out);
    fileout << GCD_all_elements_array(a, n);
    fileout.close();

    fileout.open("LCM_array.txt", ios_base::out);
    fileout << LCM_all_elements_array(a, n);
    fileout.close();
    return 0;
}