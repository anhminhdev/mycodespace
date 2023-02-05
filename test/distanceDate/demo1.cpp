#include <iostream>
using namespace std;

bool isLeapYear(int year);
int dateOfFirstYear(int day1, int month1, int year1, int arr[]);
int dateOfLastYear(int day2, int month2, int year2, int arr[]);

int main()
{
    int day1, month1, year1, day2, month2, year2;
    // Input date
    cout << "Enter date (day / month / year) from: ";
    cin >> day1 >> month1 >> year1;
    cout << "Enter date (day / month / year) to: ";
    cin >> day2 >> month2 >> year2;

    // Array contain months of year
    int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int soNgayConLai = dateOfFirstYear(day1, month1, year1, arr);
    int soNgayNamCuoi = dateOfLastYear(day2, month2, year2, arr);

    if (year1 != year2)
    {
        int distanceYear = 0;
        for (int i = year1 + 1; i < year2; i++)
        {
            if (isLeapYear(i))
                distanceYear += 366;
            else
                distanceYear += 365;
        }
        // In ra màn hình khoảng cách giữa 2 ngày tính cả ngày cuối cùng
        cout << "Different between two dates is: " << soNgayConLai + distanceYear + soNgayNamCuoi << endl;
    }
    else // year1 == year2
    {
        int result;
        if (isLeapYear(year1))
            result = soNgayNamCuoi - (366 - soNgayConLai);
        else
            result = soNgayNamCuoi - (365 - soNgayConLai);

        cout << "Different between two dates is: " << result << endl;
    }
    return 0;
}

bool isLeapYear(int year)
{
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

// Tính số ngày còn lại của năm đầu tiên
int dateOfFirstYear(int day1, int month1, int year1, int arr[])
{
    int distanceYear1 = 0;
    if (isLeapYear(year1))
    {
        arr[1] = 29;
        for (int i = 0; i < month1 - 1; i++)
        {
            distanceYear1 += arr[i];
        }
        distanceYear1 += day1;
        distanceYear1 = 366 - distanceYear1;
    }
    else
    {
        arr[1] = 28;
        for (int i = 0; i < month1 - 1; i++)
        {
            distanceYear1 += arr[i];
        }
        distanceYear1 += day1;
        distanceYear1 = 365 - distanceYear1;
    }
    return distanceYear1;
}

// Tính số ngày của năm cuối cùng
int dateOfLastYear(int day2, int month2, int year2, int arr[])
{
    int dateOfYear2 = 0;
    if (isLeapYear(year2))
    {
        arr[1] = 29;
        for (int i = 0; i < month2 - 1; i++)
        {
            dateOfYear2 += arr[i];
        }
        dateOfYear2 += day2;
    }
    else
    {
        arr[1] = 28;
        for (int i = 0; i < month2 - 1; i++)
        {
            dateOfYear2 += arr[i];
        }
        dateOfYear2 += day2;
    }
    return dateOfYear2;
}