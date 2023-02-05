#include <iostream>
#include <string>
using namespace std;

int length_of_number(int num)
{
  return to_string(num).length();
}

void inputMatrix(int a[][100], int &r, int &c)
{
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> a[i][j];
    }
  }
}

void printSpace(int n)
{
  for (int i = 1; i <= n; i++)
  {
    cout << ' ';
  }
}

int main()
{
  int r, c;
  int a[100][100];
  int amount[100];
  inputMatrix(a, r, c);
  // đếm số có số lượng chữ số lớn nhất trong từng cột từng cột
  for (int j = 0; j < c; j++)
  {
    int max = length_of_number(a[0][j]);
    for (int i = 1; i < r; i++)
    {
      if (length_of_number(a[i][j]) > max)
        max = length_of_number(a[i][j]);
    }
    amount[j] = max;
  }
  // print matrix result
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (length_of_number(a[i][j] < amount[j]))
      {
        printSpace(amount[j] - length_of_number(a[i][j]));
        cout << a[i][j] << ' ';
      }
      else if (length_of_number(a[i][j] == amount[j]))
      {
        cout << a[i][j] << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
