#include <iostream>
#include <set>
using namespace std;

// 3 hàm: insert, find, count có độ phức tạp là O(log n)

int main()
{
    // Khai báo set s các phần tử kiểu dữ liệu int (các phần tử trong set là kiểu số nguyên)
    set<int> s;
    int a[10];

    // Nhập mảng a
    for (int i = 0; i < 5; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Đưa các phần tử mảng a vào trong set
    // Lưu ý: các phần tử trong set sẽ theo thứ tự từ nhỏ đến lớn
    for (int i = 0; i < 5; i++)
    {
        s.insert(a[i]);
    }
    // In kích cỡ của set
    cout << "Size of set: " << s.size() << endl;

    // Tìm phần tử có trong set hay không? (dùng hàm count)
    if (s.count(9)) // Nếu tìm thấy phần tử 9 có trong set
        cout << "Found\n";
    else
        cout << "Not found\n";

    // Tìm phần tử có trong set hay không? (dùng hàm find)
    if (s.find(9) != s.end()) // Nếu tìm thấy phần tử 9 có trong set
        cout << "Found\n";
    else
        cout << "Not found\n";

    return 0;
}
