#include <string>
#include <iostream>
using namespace std;

class Birthday
{
private:
    int day, month, year;

public:
    void inputBirth();
    void outputBirth();
};

class HocSinh
{
private:
    string name;
    float math, literary;
    Birthday birth;

public:
    void inputStudentInfo();
    void outputStudentInfo();
    double calcAverage();
};
