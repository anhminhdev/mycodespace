#include <iostream>
using namespace std;
#define Loan 100

// Calculate total money student must payment
long double totalMoney(int year, double interest)
{
  if (year == 0)
    return Loan;
  return totalMoney(year - 1, interest) * (1 + interest / 100);
}

int main()
{
  int year;
  float interest;
  cout << "Enter the number of years loan: ";
  cin >> year;
  cout << "Enter interest (percent) each year: ";
  cin >> interest;

  cout << "Total money student payment: " << totalMoney(year, interest);
  return 0;
}