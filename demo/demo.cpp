#include <iostream>
using namespace std;
typedef struct Fraction
{
  int numerator, denominator;
} Frac;

istream &operator>>(istream &is, Frac &p)
{
  cout << "Enter numerator: ";
  is >> p.numerator;
  cout << "Enter denominator: ";
  is >> p.denominator;
  return is;
}

ostream &operator<<(ostream &os, Frac p)
{
  os << "Numerator: " << p.numerator << endl;
  os << "Denominator: " << p.denominator << endl;
  return os;
}

Frac operator+(Frac p1, Frac p2)
{
  Frac sum;
  sum.numerator = p1.numerator * p2.denominator + p1.denominator * p2.numerator;
  sum.denominator = p1.denominator * p2.denominator;
  return sum;
}

Frac operator-(Frac p1, Frac p2)
{
  Frac diff;
  diff.numerator = p1.numerator * p2.denominator - p1.denominator * p2.numerator;
  diff.denominator = p1.denominator * p2.denominator;
  return diff;
}

int main()
{
  Fraction p1, p2;
  cin >> p1;
  cout << p1;
  cin >> p2;
  cout << p2;

  cout << "Diff: " << (p1 - p2).numerator << " / " << (p1 - p2).denominator << endl;
  return 0;
}