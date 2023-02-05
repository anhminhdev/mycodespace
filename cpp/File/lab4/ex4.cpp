// r(remainder): số dư
// numerator: tử số
// denominator: mẫu số

#include <iostream>
#include <fstream>
using namespace std;

struct Fraction
{
    int numerator, denominator;
};

// Function read fraction from file
void readOneFraction(ifstream &filein, Fraction &frac)
{
    filein >> frac.numerator;
    char ch;
    // Read the character '/' to ch variable
    filein >> ch;
    filein >> frac.denominator;
}

void readListFraction(ifstream &filein, Fraction list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        readOneFraction(filein, list[i]);
    }
}

// Read file and read fraction from file
void openFile_readFile(ifstream &filein, Fraction list[], int &n)
{
    filein.open("input.txt", ios_base::in);
    // Read the amount fraction to n variable
    filein >> n;
    readListFraction(filein, list, n);
    filein.close();
}

void printOneFraction(Fraction frac)
{
    cout << frac.numerator << " / " << frac.denominator << endl;
}

void printListFraction(Fraction list[], int n)
{
    cout << "\nList fraction:\n";
    for (int i = 0; i < n; i++)
    {
        printOneFraction(list[i]);
    }
}

// Find greatest common divisor by Euclide algorithm
int GCD(int a, int b)
{
    // if (b == 0)
    //     return a;
    // return GCD(b, a % b);
    return b == 0 ? a : GCD(b, a % b);
}

void reduceFraction(Fraction list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int gcd = GCD(list[i].numerator, list[i].denominator);

        list[i].numerator /= gcd;
        list[i].denominator /= gcd;
    }
}

// Write reduced fraction to file "reducedFraction.txt"
void writeReducedFractionToFile(ofstream &fileout, Fraction list[], int n)
{
    reduceFraction(list, n);
    fileout.open("reducedFraction.txt", ios_base::out);
    for (int i = 0; i < n; i++)
    {
        fileout << list[i].numerator << " / " << list[i].denominator << endl;
    }
    fileout.close();
}

// Get result each element in struct fraction array
void getResultFraction(double temp[], Fraction list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        temp[i] = (double)list[i].numerator / list[i].denominator;
    }
}

double maxElementOfArray(double temp[], int n, Fraction list[])
{
    getResultFraction(temp, list, n);
    double max = temp[0];
    for (int i = 0; i < n; i++)
    {
        if (temp[i] > max)
            max = temp[i];
    }
    return max;
}

int indexMaxFraction(double temp[], int n, Fraction list[])
{
    double max = maxElementOfArray(temp, n, list);
    int i = 0;
    for (; i < n; i++)
    {
        if (temp[i] == max)
            break;
    }
    return i;
}

// Write max element fraction to file
void writeMaxFractionToFile(ofstream &fileout, Fraction list[], int n, double temp[])
{
    fileout.open("maxFraction.txt", ios_base::out);

    int i = indexMaxFraction(temp, n, list);
    fileout << list[i].numerator << " / " << list[i].denominator;

    fileout.close();
}

int main()
{
    Fraction frac;
    ifstream filein;
    ofstream fileout;
    Fraction list[100];
    double temp[100];
    int n;

    openFile_readFile(filein, list, n);
    writeReducedFractionToFile(fileout, list, n);
    writeMaxFractionToFile(fileout, list, n, temp);
    return 0;
}

// CÁCH 2: Find max fraction in struct array

void cach_nay_HAY_hon(ofstream &fileout, Fraction list[], int n)
{
    double max = list[0].numerator / list[0].denominator;
    // Initialize index variable hold max fraction
    int index;
    for (int i = 0; i < n; i++)
    {
        double temp = list[i].numerator / list[i].denominator;
        if (temp > max)
        {
            max = temp;
            index = i;
        }
    }

    fileout.open("maxFraction.txt", ios_base::out);

    fileout << list[index].numerator << " / " << list[index].denominator;

    fileout.close();
}