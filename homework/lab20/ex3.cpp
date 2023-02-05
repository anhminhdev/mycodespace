/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct DATE
{
    int day, month, year;
};
typedef struct STUDENT
{
    char id[11];
    char name[35];
    DATE dob;
    float math, phy, chem, aver;

} SV;

// ###INSERT CODE HERE -
void input_one_student(SV &x)
{
    cin >> x.id;
    cin.ignore();
    cin.getline(x.name, sizeof(x.name));
    cin >> x.dob.day >> x.dob.month >> x.dob.year;
    cin >> x.math >> x.phy >> x.chem;
}

void inputArrayStudents(SV a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        input_one_student(a[i]);
    }
}

double average(SV &sv)
{
    return (sv.math + sv.phy + sv.chem) / 3.0;
}

void outputStudent(SV x)
{
    cout << x.id << "\t"
         << "|" << x.name << "\t"
         << "|" << x.dob.day << "/" << x.dob.month << "/" << x.dob.year << "\t"
         << "|" << x.math << "\t"
         << "|" << x.phy << "\t"
         << "|" << x.chem << "\t"
         << "|" << average(x) << endl;
}

int findStudent(SV a[], int n, char search_name[])
{
    int length = strlen(search_name);
    int i = 0;
    for (; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; j < length; j++)
        {
            if (search_name[j] != a[i].name[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            return i;
    }
    return -1;
}

int main()
{
    STUDENT a[100];
    int n, i;
    char name[35];

    inputArrayStudents(a, n);

    cout << "\nFind a student with name: ";
    cin.ignore();
    cin.getline(name, 35);
    i = findStudent(a, n, name);
    if (i == -1)
        cout << "\nNo Found.";
    else
    {
        cout << "\nID\t|Fullname\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
        outputStudent(a[i]);
    }

    return 0;
}
