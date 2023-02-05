/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
struct node
{
  int data;
  node *next;
};

struct list
{
  node *head, *tail;
};

void initList(list &l)
{
  l.head = l.tail = NULL;
}

int main()
{

  return 0;
}