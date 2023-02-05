#include "HocSinh.h"

int main()
{
    HocSinh hs;
    hs.inputStudentInfo();
    hs.outputStudentInfo();
    double aver = hs.calcAverage();
    cout << "Average score: " << aver << endl;
    return 0;
}