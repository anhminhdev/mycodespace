#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

struct List
{
  Node *head, *tail;
};

void initList(List &l)
{
  l.head = l.tail = NULL;
}

Node *createNode(int data)
{
  Node *p = new Node;
  p->data = data;
  p->next = NULL;
  return p;
}

// Add node to the end of the list
void addNodeIntoLastList(List &l, Node *add)
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

void inputDataNode(List &l)
{
  initList(l);

  cout << "Enter the number of nodes: ";
  int num;
  cin >> num;
  for (int i = 1; i <= num; i++)
  {
    cout << "Enter data node " << i << ": ";
    int data;
    cin >> data;
    Node *p = createNode(data);
    addNodeIntoLastList(l, p);
  }
}

void outputDataNode(List l)
{
  cout << "\nData linked list: ";
  for (Node *i = l.head; i != NULL; i = i->next)
  {
    cout << i->data << " ";
  }
}
void releaseListMemory(List &l)
{
  Node *i;
  while (l.head != NULL)
  {
    i = l.head;
    l.head = l.head->next;
    delete i;
  }
  cout << "\nReleased list memory.";
}

void deleteNodeLastList(List &l)
{
  if (l.head == NULL)
  {
    return;
  }
  // if list only have one node
  else if (l.head->next == NULL)
  {
    Node *del = l.head;
    l.head = l.head->next;
    delete del;
  }
  else
  {
    Node *prev;
    for (Node *i = l.head; i != NULL; i = i->next)
    {
      if (i == l.tail)
      {
        l.tail = prev;
        l.tail->next = NULL;
        delete i;
        return;
      }
      prev = i;
    }
  }
}

void addNodeIntoHeadList(List &l, Node *add)
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

void convertLastNodeToHeadList(List &l)
{
  // Idea: delete last node (before delete node, save the data) then add into head list
  int dataLastNode = l.tail->data;
  Node *convert = createNode(dataLastNode);
  deleteNodeLastList(l);
  addNodeIntoHeadList(l, convert);
}

int main()
{
  List l;
  inputDataNode(l);
  outputDataNode(l);

  convertLastNodeToHeadList(l);
  outputDataNode(l);
  return 0;
}