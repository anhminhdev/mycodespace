#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#define lengthTable 78

struct DEV
{
    char name[30];
    int age;
    char sex[10];
    char gun[20];
    char pos[30];
};

void inputInformation(DEV dev[], int n)
{
    cin.ignore();
    for (int i = 0; i < n; i++)
    {

        cout << "Nhap thong tin Dev thu " << i + 1 << ":\n";
        cout << "Nhap ho va ten: ";
        cin.getline(dev[i].name, sizeof(dev[i].name));
        cout << "Nhap tuoi: ";
        cin >> dev[i].age;
        cin.ignore();
        cout << "Nhap gioi tinh: ";
        cin.getline(dev[i].sex, sizeof(dev[i].sex));
        cout << "Nhap chieu dai sung: ";
        cin.getline(dev[i].gun, sizeof(dev[i].gun));
        cout << "Nhap chuc vu trong phong: ";
        cin.getline(dev[i].pos, sizeof(dev[i].pos));
    }
}

void printInformation(DEV dev[], int n)
{
    for (int i = 0; i < lengthTable; i++)
    {
        cout << "_";
    }
    cout << endl;

    cout << "|STT|" << setw(21) << left << "Ho va ten" << setw(9) << "|Tuoi |" << setw(2) << left << "Gioi tinh" << setw(19) << left << "| Chieu dai Sung |" << setw(15) << "Chuc vu       |" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "|" << setw(2) << i + 1 << " |"
             << setw(21) << left << dev[i].name << "|"
             << setw(5) << left << dev[i].age << "|"
             << setw(11) << left << dev[i].sex << "|"
             << setw(16) << left << dev[i].gun << "|"
             << setw(15) << left << dev[i].pos << "|" << endl;
    }
}

void nhapSoluongDev(int &n)
{
    do
    {
        cout << "Nhap so luong Dev: ";
        cin >> n;
        if (n < 1)
            cout << "So luong Dev khong hop le. Vui long nhap lai!" << endl;
    } while (n < 1);
}

void Menu()
{
    cout << "========================================\n";
    cout << "\tQuan ly Dev phong 1011\n";
    cout << "========================================\n";
    cout << "1. Nhap thong tin Dev." << endl;
    cout << "2. Hien thi danh sach thong tin Dev." << endl;
    cout << "0. Thoat" << endl;
}

int main()
{
    DEV dev[100];
    int n;
    int choice;
    char choiceContinue;

    do
    {
        Menu();

        cout << "Moi ban nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            nhapSoluongDev(n);
            inputInformation(dev, n);
            break;
        case 2:
            printInformation(dev, n);
            break;
        case 0:
            break;
        default:
            cout << "Lua chon cua ban khong hop le!\n";
            break;
        }
        cout << "Ban co muon lua chon tiep khong? (Y/N): ";
        cin >> choiceContinue;
        if (choiceContinue == 'n' || choiceContinue == 'N')
            cout << "Tam biet!\n";
    } while (choiceContinue == 'y' || choiceContinue == 'Y');

    return 0;
}