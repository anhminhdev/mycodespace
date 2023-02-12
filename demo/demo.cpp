#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
  node *pre;
};

struct douList
{
  node *head;
  node *tail;
};

douList *initList(int x)
{
  douList *l = new douList;
  l->head = new node;
  l->head->data = x;
  l->head->pre = NULL;
  l->head->next = NULL;
  l->tail = l->head;
  return l;
}

douList *addHead(douList *l, int x)
{
  node *temp = new node;
  temp->data = x;
  temp->pre = NULL;
  temp->next = l->head;
  l->head->pre = temp;
  l->head = temp;
  return l;
}

douList *addTail(douList *l, int x)
{
  node *temp = new node;
  temp->data = x;
  temp->next = NULL;
  temp->pre = l->tail;
  l->tail->next = temp;
  l->tail = temp;
  return l;
}

void printList(douList *l)
{
  for (node *i = l->head; i != NULL; i = i->next)
  {
    cout << i->data << " ";
  }
}

int main()
{
  int n;
  cin >> n;
  douList *l = initList(1);
  for (int i = 2; i <= n; i++)
  {
    l = addHead(l, i);
    l = addTail(l, i);
  }
  printList(l);
  return 0;
}