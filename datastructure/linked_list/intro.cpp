#include <iostream>
using namespace std;

// Khai báo 1 cấu trúc Node
struct NODE
{
    int data;    // dữ liệu trong 1 cái Node
    NODE *pNext; // con trỏ để liên kết các Node với nhau
};

// Khai báo 1 cấu trúc danh sách liên kết
struct LIST
{
    NODE *pHead; // khai báo Node quản lý đầu danh sách
    NODE *pTail; // Khai báo Node quản lý cuối danh sách
};

// Khởi tạo danh sách liên kết đơn
void initList(LIST &l)
{
    // cho 2 con trỏ pHead, pTail trỏ đến NULL - vì danh sách liên kết lúc này chưa có phần tử
    l.pHead = l.pTail = NULL;
}

// Hàm khởi tạo 1 cái Node
NODE *initNode(int x) // x là dữ liệu từ bên ngoài
{
    // Cấp phát vùng nhớ(địa chỉ) của Node cho biến con trỏ p
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "Khong du bo nho de cap phat!";
        return NULL;
    }
    p->data = x;     // truyền giá trị x vào cho data
    p->pNext = NULL; // Node sẽ chưa liên kết đến Node khác
    return p;        // trả về Node p vừa khởi tạo
}

// Hàm thêm Node p vào đầu danh sách liên kết
void addNodeHeadList(LIST &l, NODE *p)
{
    if (l.pHead == NULL)       // danh sách rỗng
        l.pHead = l.pTail = p; // Node thêm vào là Node đầu danh sách và cũng là Node cuối danh sách
    else
    {
        p->pNext = l.pHead; // Quăng dây liên kết
        l.pHead = p;        // con trỏ pHead lúc này sẽ chạy ra ở vị trí Node p
    }
}

// Hàm thêm Node p vào cuối danh sách liên kết
void addNodeEndList(LIST &l, NODE *p)
{
    if (l.pHead == NULL)       // danh sách rỗng
        l.pHead = l.pTail = p; // Node thêm vào là Node đầu danh sách và cũng là Node cuối danh sách
    else
    {
        l.pTail->pNext = p; // Quăng dây liên kết NGƯỢC LẠI VỚI THÊM VÀO ĐẦU DANH SÁCH
        l.pTail = p;        // con trỏ pTail lúc này sẽ trỏ đến vị trí Node p
    }
}

// Xuất danh sách liên kết
void printLinkedList(LIST l)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
        cout << p->data << ' ';
}

// Hàm tìm giá trị lớn nhất trong danh sách liên kết đơn các số nguyên
int maxLinkedList(LIST l, NODE *p)
{
    // l.pHead là Node đầu của danh sách
    int max = l.pHead->data;
    // Bắt đầu duyệt từ phần tử thứ 2
    for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if (p->data > max)
            max = p->data;
    }
    return max;
}

int main()
{
    LIST l;
    NODE *p;
    initList(l); // NHỚ KHÔNG ĐƯỢC QUÊN: KHỞI TẠO DANH SÁCH LIÊN KẾT ĐƠN***
    int n;
    cout << "Enter amount Nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap vao so nguyen: ";
        cin >> x;
        NODE *p = initNode(x); // Khởi tạo 1 cái Node
        addNodeEndList(l, p);
        // addNodeHeadList(l, p);
    }

    cout << "Danh sach lien ket don:\n";
    printLinkedList(l);
    cout << "\nGia tri lon nhat trong danh sach la: " << maxLinkedList(l, p) << endl;
    return 0;
}