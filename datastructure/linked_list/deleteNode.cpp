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

void initList(list &l)
{
    l.pHead = l.pTail = NULL;
}

node *createNode(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->pNext = NULL;
    return temp;
}

// Thêm node p vào cuối danh sách
void addNodeEndList(list &l, node *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Nhập dữ liệu của Node
void inputNode(list &l)
{
    initList(l);

    cout << "Nhap so luong Node: ";
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap du lieu so nguyen cua Node: ";
        int x;
        cin >> x;
        node *temp = createNode(x);
        addNodeEndList(l, temp);
    }
}

// In danh sách liên kết
void printList(list l)
{
    cout << "\nDanh sach lien ket don:\n";
    for (node *i = l.pHead; i != NULL; i = i->pNext)
        cout << i->data << ' ';
}

// Xóa node đầu danh sách đơn
void deleteNodeHeadList(list &l)
{
    // Nếu danh sách rỗng
    if (l.pHead == NULL)
        return;
    else
    {
        // Khởi tạo node p trỏ đến địa chỉ của node đầu danh sách
        node *p = l.pHead;
        // Cho con trỏ pHead trỏ đến node kế tiếp
        l.pHead = l.pHead->pNext;
        // Xóa node p tức là đang xóa node đầu danh sách
        delete p;
    }
}

// Xóa node cuối danh sách đơn
void deletNodeEndList(list &l)
{
    // Nếu danh sách đang rỗng
    if (l.pHead == NULL)
        return;
    // Nếu danh sách chỉ có 1 phần tử
    else if (l.pHead->pNext == NULL)
    {
        // //CÁCH 1: (tốn bộ nhớ vì node vẫn sẽ chưa được xóa hoàn toàn khỏi bộ nhớ của máy tính)
        // // Cho con trỏ pHead, pTail không quản lý node nào nữa -> danh sách không còn chứa node
        // l.pHead = l.pTail = NULL;
        // return;

        // CÁCH 2:
        deleteNodeHeadList(l);
        return;
    }
    else
    {
        node *p = l.pTail;
        for (node *i = l.pHead; i != NULL; i = i->pNext)
        {
            if (i->pNext == l.pTail)
            {
                // Xóa node cuối danh sách
                delete l.pTail;
                // Cho con trỏ ở node kế cuối trỏ đến vùng nhớ rỗng
                i->pNext = NULL;
                // Cập nhật lại con trỏ pTail
                l.pTail = i;
                return;
            }
        }
    }
}

// Xóa 1 node nằm sau node q
void xoa1NodeNamSauNode_q(list &l)
{
    // Nhập node q
    int x;
    cout << "\nNhap du lieu cua node q: ";
    cin >> x;
    node *q = createNode(x);
    // nếu danh sách chỉ có 1 phần tử
    if (l.pHead->pNext == NULL)
        deleteNodeHeadList(l);
    else
    {
        for (node *i = l.pHead; i != NULL; i = i->pNext)
        {
            if (i->data == q->data)
            {
                // khởi tạo node g là node cần xóa (node g là node nằm sau node q)
                node *g = i->pNext;
                // quăng dây liên kết từ node i(node q) đến cái node nằm sau node g
                i->pNext = g->pNext;
                delete g;
            }
            // ###CÁCH LÀM Ở TRÊN VẪN CÒN SAI VÀI TRƯỜNG HỢP: {1,2,2,2,2}, {2,2,2,2}...###
        }
    }
}

// Xóa 1 node bất kì trong danh sách có dữ liệu bằng số nguyên k nhập từ bàn phím
void xoaNodeCoKhoaBatKy(list &l)
{
    cout << "\nNhap so nguyen k: ";
    int k;
    cin >> k;
    if (l.pHead == NULL) // nếu danh sách rỗng
        return;
    else if (l.pHead->pNext == NULL) // nếu danh sách chỉ có 1 node
    {
        deleteNodeHeadList(l);
        return;
    }
    else // danh sách có 2 node trở lên
    {
        node *temp = new node;
        for (node *i = l.pHead; i != NULL; i = i->pNext)
        {
            // nếu node đầu danh sách có dữ liệu bằng k (node cần xóa nằm đầu danh sách)
            if (l.pHead->data == k)
            {
                deleteNodeHeadList(l);
                return;
            }
            else if (i->data == k)
            {
                // tạo mối liên kết từ node temp đến sau node i
                temp->pNext = i->pNext;
                delete i;
                return;
            }
            temp = i;
        }
    }
}

// Giải phóng vùng nhớ cho danh sách liên kết đơn
void giaiPhongVungNho(list &l)
{
    cout << "\nDa giai phong vung nho cua danh sach lien ket" << endl;
    for (node *i = l.pHead; i != NULL; i = i->pNext)
    {
        // cập nhật lại con trỏ pHead để giải phóng toàn bộ node trong danh sách
        l.pHead = l.pHead->pNext; 
        // giải phóng vùng nhớ của node i
        delete i;
        
    }
}

int main()
{
    list l;
    inputNode(l);
    printList(l);
    // Thực hiện yêu cầu bài toán
    giaiPhongVungNho(l);
    // In lại danh sách liên kết để kiểm tra
    printList(l);
    return 0;
}