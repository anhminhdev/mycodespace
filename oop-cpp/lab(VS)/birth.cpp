#include "HocSinh.h"

void Birthday::inputBirth()
{
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
}

void Birthday::outputBirth()
{
    cout << "Birth date: " << day << '/' << month << '/' << year << endl;
}