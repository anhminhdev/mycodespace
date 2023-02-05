#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Count digits number in file
void readFile(ifstream &fileIn)
{
    fileIn.open("D:/codeSpace/test/progTechniques/kc3/ex3.txt", ios_base::in);
    // Check file exist
    if (!fileIn)
    {
        cout << "Not found file ex3.txt";
        return;
    }
    int count = 0;
    while (!fileIn.eof())
    {
        string str;
        getline(fileIn, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]))
                count++;
        }
        // cout << str << endl;
    }
    cout << "Digits number in file: " << count;
    fileIn.close();
}

int main()
{
    ifstream fileIn;
    readFile(fileIn);
    return 0;
}