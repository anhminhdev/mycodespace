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

void printTree(node *t)
{
  if (t != NULL)
  {
    printTree(t->left);
    cout << t->data << ' ';
    printTree(t->right);
  }
}

int treeLevel(node *t)
{
  if (t == NULL)
    return -1;
  return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

bool checkAVL(node *t)
{
  if (t == NULL)
    return true;
  if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1)
    return false;
  return checkAVL(t->left) && checkAVL(t->right);
}

int main()
{
  int n, x;
  cin >> n;
  node *t = NULL;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    t = insert(t, x);
  }
  cout << std::boolalpha << checkAVL(t);
  return 0;
}