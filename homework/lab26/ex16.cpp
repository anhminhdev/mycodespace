/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

// ###INSERT CODE HERE -
using namespace std;

int main()
{
  int n;
  int a[2000], b[2000]; // khai báo 2 mảng a và b
  int ans = 0;          // biến đếm kết quả

  cin >> n; // nhập số lượng phần tử
  for (int i = 0; i < n; i++)
    cin >> a[i]; // nhập mảng a
  for (int i = 0; i < n; i++)
    cin >> b[i]; // nhập mảng b

  for (int i = 0; i < n; i++)
  { // vòng lặp qua từng phần tử trong mảng a
    for (int j = 0; j < n; j++)
    { // vòng lặp qua từng phần tử trong mảng b
      if (a[i] == b[j])
      { // nếu phần tử trong mảng a bằng phần tử trong mảng b
        for (int k = j + 1; k < n; k++)
        { // vòng lặp qua các phần tử sau phần tử trong mảng b
          if (b[k] < b[j])
            ans++; // nếu phần tử sau nhỏ hơn phần tử đang xét, tăng biến đếm lên 1
        }
        break; // thoát khỏi vòng lặp đang duyệt trong mảng b
      }
    }
  }
  cout << ans; // in kết quả
  return 0;
}
