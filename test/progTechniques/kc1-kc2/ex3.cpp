#include <iostream>
#include <string>
using namespace std;

typedef struct CUSTOMER
{
    string id, name, addr, phone, mail;
} cus;

typedef struct NODE
{
    cus data;
    NODE *next;
};

struct LIST
{
    NODE *head, *tail;
};

// Initialize linked list
void initList(LIST &l)
{
    l.head = l.tail = NULL;
}

NODE *createNode(cus data)
{
    // Memory allocation of NODE to pointer p variable
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "Not enough memory to allocate!";
        return NULL;
    }
    p->data = data;
    p->next = NULL;
    return p;
}

void addNodeIntoHeadList(LIST &l, NODE *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void addNodeIntoTailList(LIST &l, NODE *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void enterInfoCustomer(LIST &l, CUSTOMER &cus)
{
    cout << "Enter Customer Information:\n";
    do
    {
        fflush(stdin);
        cout << "Enter Id: ";
        getline(cin, cus.id);
        if (cus.id.length() > 14)
            cout << "ID invalid. Please enter again!\n";
    } while (cus.id.length() > 14);

    cout << "Enter Name: ";
    getline(cin, cus.name);

    cout << "Enter Address: ";
    getline(cin, cus.addr);

    cout << "Enter Phone numbers: ";
    getline(cin, cus.phone);

    cout << "Enter Mail: ";
    getline(cin, cus.mail);
}

void input(LIST &l)
{
    initList(l);

    int n;
    cout << "Enter customer numbers: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Customer information " << i << ":\n";

        cus data;
        enterInfoCustomer(l, data);

        NODE *p = createNode(data);
        addNodeIntoTailList(l, p);
    }
}

void printCustomerInfo(CUSTOMER cus)
{
    cout << "Id: " << cus.id << endl;
    cout << "Name: " << cus.name << endl;
    cout << "Address: " << cus.addr << endl;
    cout << "Phone: " << cus.phone << endl;
    cout << "Mail: " << cus.mail << endl;
}

void output(LIST l)
{
    int cnt = 1;
    for (NODE *p = l.head; p != NULL; p = p->next)
    {
        cout << "Customer information " << cnt++ << ":\n";
        printCustomerInfo(p->data);
    }
}

void releaseMemory(LIST &l)
{
    NODE *temp;
    while (l.head != NULL)
    {
        // Pointer temp point to node head list
        temp = l.head;
        l.head = l.head->next;
        delete temp;
    }
}

int main()
{
    LIST l;
    input(l);
    output(l);

    releaseMemory(l);
    return 0;
}