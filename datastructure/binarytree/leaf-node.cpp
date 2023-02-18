#include <iostream>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};
node *insert(node *t, int x)
{
  if (t == NULL)
  {
    node *temp = new node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }
  else
  {
    if (x < t->data)
    {
      t->left = insert(t->left, x);
    }
    else
    {
      t->right = insert(t->right, x);
    }
  }
  return t;
}

bool isLeafNode(node *l)
{
  return (l->left == NULL && l->right == NULL);
}

int treeLevel(node *t)
{
  if (t == NULL)
    return -1;
  return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

int main()
{
  int n, temp;
  cin >> n;
  node *t = NULL;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    t = insert(t, temp);
  }
  cout << treeLevel(t);

  return 0;
}