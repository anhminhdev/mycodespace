#include <iostream>
using namespace std;

// Delete all element is odd number in linked list

typedef struct NODE
{
    int data;
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

node *createNode(int data)
{
    node *res = new node;
    res->data = data;
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

void inputNode(list &l)
{
    initList(l);

    int num;
    cout << "Enter Node numbers: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cout << "Enter data integer number of node " << i << ": ";
        int data;
        cin >> data;

        node *temp = createNode(data);
        addNodeTailList(l, temp);
    }
}

void outputNode(list l)
{
    cout << "\nData linked list: ";
    for (node *i = l.head; i != NULL; i = i->next)
    {
        cout << i->data << ' ';
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
        if (i->data == p->data)
        {
            // Initialize node del behind node p
            node *del = i->next;
            i->next = del->next;
            delete del;
            return;
        }
    }
}

// Delete all element is odd number data
void deleteOddElement(list &l)
{
    // Initialize node prev as node previous node i
    node *prev = l.head;
    // Traverse list from second node
    for (node *i = l.head->next; i != NULL; i = i->next)
    {
        if (i->data % 2 != 0)
        {
            deleteNodeBehind(l, prev);
            // Back to the previous node
            i = prev;
        }
        prev = i;
    }
    if (l.head->data % 2 != 0)
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

    deleteOddElement(l);
    outputNode(l);
    releaseListMemory(l);
    return 0;
}