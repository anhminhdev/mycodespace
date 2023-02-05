#include <iostream>
#include <string>
using namespace std;

// Delete all books published before 2000

struct BOOK
{
    string id, name, publisher;
    int Mfg, price;
};

typedef struct NODE
{
    BOOK data;
    NODE *next;
} node;

typedef struct LIST
{
    NODE *head, *tail;
} list;

void initList(list &l)
{
    l.head = l.tail = NULL;
}

node *createNode(BOOK info)
{
    node *res = new node;
    res->data = info;
    res->next = NULL;
    return res;
}

void addNodeTailList(list &l, node *add)
{
    if (l.head == NULL)
    {
        l.head = l.tail = add;
    }
    else
    {
        l.tail->next = add;
        l.tail = add;
    }
}

void addNodeHeadList(list &l, node *add)
{
    if (l.head == NULL)
    {
        l.head = l.tail = add;
    }
    else
    {
        add->next = l.head;
        l.head = add;
    }
}

void inputBook(BOOK &x)
{
    cin.ignore();
    cout << "Enter Id Book: ";
    getline(cin, x.id);
    cout << "Enter Name Book: ";
    getline(cin, x.name);
    cout << "Enter Publisher Book: ";
    getline(cin, x.publisher);
    cout << "Enter the year of production of the Book: ";
    cin >> x.Mfg;
    cout << "Enter price of Book: ";
    cin >> x.price;
}

void inputNode(list &l)
{
    initList(l);

    int num;
    cout << "Enter Book numbers: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cout << "Enter book information " << i << ":\n";
        BOOK info;
        inputBook(info);

        node *temp = createNode(info);
        addNodeTailList(l, temp);
    }
}

void outputBook(BOOK x)
{
    cout << "Id Book: " << x.id << endl;
    cout << "Name Book: " << x.name << endl;
    cout << "Publisher Book: " << x.publisher << endl;
    cout << "The year of production of the Book: " << x.Mfg << endl;
    cout << "Price of Book: " << x.price << endl;
}

void outputNode(list l)
{
    cout << "\nBOOK information in linked list:\n";
    for (node *i = l.head; i != NULL; i = i->next)
    {
        // int cnt = 1;
        // cout << "Book information " << cnt++ << ":\n";
        outputBook(i->data);
    }
}

void deleteNodeHeadList(list &l)
{
    if (l.head == NULL)
    {
        return;
    }
    else
    {
        node *del = l.head;
        l.head = l.head->next;
        delete del;
    }
}

void deleteNodeTailList(list &l)
{
    if (l.head == NULL)
    {
        return;
    }
    // List only have 1 node
    else if (l.head->next == NULL)
    {
        deleteNodeHeadList(l);
        return;
    }
    else
    {
        node *del = l.tail;
        for (node *i = l.head; i != NULL; i = i->next)
        {
            if (i->next == l.tail)
            {
                delete l.tail;
                i->next = NULL;
                l.tail = i;
                return;
            }
        }
    }
}

// Delete 1 node behind node p
void deleteNodeBehind(list &l, node *p)
{
    for (node *i = l.head; i != NULL; i = i->next)
    {
        if (i->data.Mfg == p->data.Mfg && i->next->data.Mfg < 2000)
        {
            // Initialize node del behind node p
            node *del = i->next;
            i->next = del->next;
            delete del;
            return;
        }
    }
}

// Delete all books published before 2000
void deleteBook(list &l)
{
    // Initialize node prev as node previous node i
    node *prev = l.head;
    // Traverse list from second node
    for (node *i = l.head->next; i != NULL; i = i->next)
    {
        if (i->data.Mfg < 2000)
        {
            deleteNodeBehind(l, prev);
            // Back to the previous node
            i = prev;
        }
        prev = i;
    }
    if (l.head->data.Mfg < 2000)
    {
        deleteNodeHeadList(l);
    }
}

void releaseListMemory(list &l)
{
    for (node *i = l.head; i != NULL; i = i->next)
    {
        l.head = l.head->next;
        delete i;
    }
    cout << "\nReleased list memory.";
}

int main()
{
    list l;
    inputNode(l);
    outputNode(l);

    deleteBook(l);
    cout << "\n\n\n";
    outputNode(l);

    releaseListMemory(l);
    return 0;
}