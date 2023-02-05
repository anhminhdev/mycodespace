#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
#define MAX 100 // amount elements of array

// Read data of file
void read_file(ifstream &filein, int a[], int &n)
{
    while (filein.eof() == false)
    {
        filein >> a[n];
        n++;
    }
}

void output_array(int a[], int n)
{
    cout << "Integers sequence is:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

// Count amount elements of integer number
int count_amount(int x)
{
    int count(0);
    while (x != 0)
    {
        count++;
        x /= 10;
    }
    return count;
}

bool is_number_amstrong(int x)
{
    int number = x; // save value x
    int count = count_amount(x);
    int res(0);
    while (x != 0)
    {
        res += pow(x % 10, count);
        x /= 10;
    }
    if (res == number)
        return true;
    else
        return false;
}

void check_elements_array(ofstream &fileout, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (is_number_amstrong(a[i]) == true)
            fileout << a[i] << ' ';
    }
}

int main()
{
    // Declare variable read file
    ifstream filein;
    // Open file
    filein.open("input.txt", ios_base::in);

    int a[MAX]; // declare array a
    int n(0);   // amount elements of array
    read_file(filein, a, n);

    filein.close();
    output_array(a, n);

    ofstream fileout;
    fileout.open("amstrong.txt", ios_base::out);

    check_elements_array(fileout, a, n);

    fileout.close();

    return 0;
}