#include <iostream>
#include <fstream>
using namespace std;
int n;  // the number of elements array
int *a; // pointer manage array
ifstream fileIn;
ofstream fileOut;
int sum = 0;

// Read data from file for array
void getDataFile(ifstream &fileIn, int &n)
{
  fileIn.open("mang1chieu.txt", ios_base::in);
  if (!fileIn)
  {
    cout << "Can't find file\n";
    return;
  }
  fileIn >> n;
  // char ch;
  // fileIn >> ch; // read character \n
  a = new int[n];
  // int i = 0;
  // while (!fileIn.eof())
  // {
  //   fileIn >> a[i++];
  //   fileIn.ignore();
  // }
  for (int i = 0; i < n; i++)
  {
    fileIn >> a[i];
    sum += a[i];
  }
  fileIn.close();
}

void writeSumToFile(ofstream &fileOut)
{
  fileOut.open("tong_mang.txt", ios_base::out);
  fileOut << sum;
  fileOut.close();
}

void outputArray()
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
  cout << endl;
}

int main()
{
  getDataFile(fileIn, n);
  outputArray();
  writeSumToFile(fileOut);
  delete[] a;
  return 0;
}