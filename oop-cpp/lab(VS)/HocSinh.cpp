#include "HocSinh.h"

void HocSinh::inputStudentInfo()
{
    fflush(stdin);
    cout << "Enter full name student: ";
    getline(cin, name);
    cout << "Enter Math score: ";
    cin >> math;
    cout << "Enter Literary score: ";
    cin >> literary;

    cout << "Enter Birthday: " << endl;
    birth.inputBirth();
}

void HocSinh::outputStudentInfo()
{
    cout << "======Student Infomation======" << endl;
    cout << "Name of student: " << name << endl;
    cout << "Math score: " << math << endl;
    cout << "Literary score: " << literary << endl;

    birth.outputBirth();
}

double HocSinh::calcAverage()
{
    return (math + literary) / 2;
}
