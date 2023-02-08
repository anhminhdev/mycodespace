#include <iostream>
using namespace std;

void inputArray(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
}

void outputArray(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void insertionSortOnArray(int *a, int n)
{
  for (int i = 1; i < n; i++)
  {
    int x = a[i];
    int j = i - 1;
    for (; j >= 0; j--)
    {
      if (a[j] > x)
      {
        a[j + 1] = a[j];
      }
      else // a[j] <= x
      {
        break;
      }
    }
    a[j + 1] = x;
  }
}

int main()
{
  cout << "Enter number of elements array: ";
  int n;
  cin >> n;
  int *a = new int[n];
  inputArray(a, n);
  outputArray(a, n);
  insertionSortOnArray(a, n);
  outputArray(a, n);
  return 0;
}

/*
void insertionSortOnLinkedList(LIST &l)
{
  for(node *i = l.head->next; i != NULL; i= i->next)
  {
    int x = i->data;
    node *j = i->rev;
    for(; j != NULL; j= j->rev)
    { 
        if(j->data > x)
        {
          j->next->data = j->data;
        }
        else
        {
          break;
        }
    }
    j->next->data = x;
  }
}
*/