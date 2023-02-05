#include <iostream>
#include <fstream>
using namespace std;

// Read data of file
void read_file(ifstream &filein, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        filein >> a[i];
    }
}

void output_array(int a[], int n)
{
    cout << "Integers sequence is:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

int max_element_array(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int main()
{
    // // Method 2: initialize character array
    // char input[] = "input.txt";
    // char result[] = "result.txt";

    // Declare variable read file
    ifstream filein;
    // Open file
    filein.open("input.txt", ios_base::in);

    int a[100]; // declare array a
    int n(0);   // amount elements of array

    filein >> n; // Read value first line of file to variable n
    read_file(filein, a, n);

    // Declare variable to write file
    ofstream fileout;
    fileout.open("result.txt", ios_base::out);

    // Write max value of array to file 
    fileout << max_element_array(a, n); 

    fileout.close();
    filein.close();

    output_array(a, n);
    return 0;
}