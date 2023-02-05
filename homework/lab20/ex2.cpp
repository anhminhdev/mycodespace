
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <math.h>
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
void input_1_student(SV &x)
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
        input_1_student(a[i]);
    }
}

double average(SV &sv)
{
    return (sv.math + sv.phy + sv.chem) / 3.0;
}

void outputArrayStudents(SV a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t"
             << "|" << a[i].name << "\t"
             << "|" << a[i].dob.day << "/" << a[i].dob.month << "/" << a[i].dob.year << "\t"
             << "|" << a[i].math << "\t"
             << "|" << a[i].phy << "\t"
             << "|" << a[i].chem << "\t"
             << "|" << average(a[i]) << endl;
    }
}

int main()
{
    STUDENT a[100];
    int n;

    inputArrayStudents(a, n);
    cout << "ID\t|Full name\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
    outputArrayStudents(a, n);

    return 0;
}
