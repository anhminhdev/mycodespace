#include <iostream>
using namespace std;

struct node
{
    int data;
    node *pNext;
};

struct list
{
    node *pHead;
    node *pTail;
};

// Khởi tạo danh sách liên kết đơn
void initList(list &l)
{
    // cho 2 con trỏ pHead, pTail trỏ đến NULL - vì danh sách liên kết lúc này chưa có phần tử
    l.pHead = l.pTail = NULL;
}

node *createNode(int x)
{
    // Cấp phát vùng nhớ (địa chỉ) của Node cho biến con trỏ p
    node *p = new node;
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat!";
        return NULL;
    }
    p->data = x;     // truyền giá trị x vào cho data
    p->pNext = NULL; // Node sẽ chưa liên kết đến Node khác
    return p;        // trả về Node p vừa khởi tạo
}

// Hàm thêm Node p vào cuối danh sách liên kết
void addNodeEndList(list &l, node *p)
{
    if (l.pHead == NULL)       // danh sách rỗng
        l.pHead = l.pTail = p; // Node thêm vào là Node đầu danh sách và cũng là Node cuối danh sách
    else
    {
        l.pTail->pNext = p; // Quăng dây liên kết NGƯỢC LẠI VỚI THÊM VÀO ĐẦU DANH SÁCH
        l.pTail = p;        // con trỏ pTail lúc này sẽ chạy ra ở vị trí Node p
    }
}

// Hàm thêm node p vào đầu danh sách
void addNodeHeadList(list &l, node *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

// Xuất danh sách liên kết
void printList(list l)
{
    cout << "Danh sach lien ket don:\n";
    for (node *i = l.pHead; i != NULL; i = i->pNext)
        cout << i->data << ' ';
}

// Thêm Node p vào sau Node q (node q nằm bất kỳ trong danh sách)
void themNode_p_vaoSauNode_q(list &l)
{
    int x;
    cout << "\nNhap du lieu Node q: ";
    cin >> x;
    node *q = createNode(x);

    int y;
    cout << "Nhap du lieu cua Node p can them vao: ";
    cin >> y;
    node *p = createNode(y);

    // Nếu danh sách chỉ có một Node và đó là node q thì bài toán trở thành thêm node vào cuối danh sách
    if (l.pHead->pNext == NULL && q->data == l.pHead->data)
        addNodeEndList(l, p);
    else
    {
        // Duyệt danh sách tìm đến node q
        for (node *i = l.pHead; i != NULL; i = i->pNext)
        {
            if (i->data == q->data)
            {
                node *h = createNode(y); // Khởi tạo node h (node phụ) có giá trị dữ liệu bằng dữ liệu của node p
                node *g = i->pNext;      // Node g là node đứng sau node q
                h->pNext = g;            // Quăng dây liên kết từ node p đến node g
                i->pNext = h;            // Quăng dây liên kết từ node q đến node p đồng thời gỡ liên kết với node g phía sau
            }
        }
    }
}

// Thêm node p vào trước node q (node q nằm bất kỳ trong danh sách)
void themNode_p_VaoTruocNode_q(list &l)
{
    int x;
    cout << "\nNhap du lieu node q: ";
    cin >> x;
    node *q = createNode(x);

    int y;
    cout << "Nhap du lieu cua Node p can them vao: ";
    cin >> y;
    node *p = createNode(y);

    // Nếu danh sách chỉ có 1 node hoặc node q là node đầu của danh sách
    if (l.pHead->pNext == NULL || q->data == l.pHead->data)
        addNodeHeadList(l, p);
    else
    {
        node *temp = new node; // Khởi tạo node temp là node đứng trước node q
        for (node *i = l.pHead; i != NULL; i = i->pNext)
        {
            if (i->data == q->data)
            {
                node *h = createNode(y);
                h->pNext = i;
                temp->pNext = h;
            }
            temp = i; // Gán node i vào node temp (mấu chốt)
        }
    }
}

// Hàm thêm node p vào vị trí bất kì trong danh sách
void themNode_p_vaoVtriBatKi(list &l, int &n)
{
    int index(0); // Biến index là chỉ số của node trong danh sách
    int pos;
    cout << "\nNhap vi tri can them: ";
    cin >> pos;

    int x;
    cout << "Nhap du lieu node p can them: ";
    cin >> x;
    node *p = createNode(x);

    // Nếu danh sách đang rỗng hoặc vị trí cần thêm là đầu danh sách
    if (l.pHead == NULL || pos == 1)
        addNodeHeadList(l, p);
    else if (pos == n + 1)
        addNodeEndList(l, p);
    else // Vị trí thêm lúc này là [2;n]
    {
        // Khởi tạo node temp là node đứng trước vị trí thêm vào
        node *temp = new node;
        for (node *i = l.pHead; i != NULL; i = i->pNext)
        {
            index++;
            if (index == pos)
            {
                p->pNext = i;
                temp->pNext = p;
                break;
            }
            temp = i;
        }
    }
}

int main()
{
    list l;
    node *p;
    initList(l); // NHỚ KHÔNG ĐƯỢC QUÊN: KHỞI TẠO DANH SÁCH LIÊN KẾT ĐƠN***

    int n;
    cout << "Nhap so luong Node: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap du lieu so nguyen cho Node: ";
        cin >> x;
        p = createNode(x); // Khởi tạo 1 cái Node
        addNodeEndList(l, p);
    }
    printList(l);
    themNode_p_vaoVtriBatKi(l, n);
    printList(l);
    return 0;
}