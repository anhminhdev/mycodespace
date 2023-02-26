#include <bits/stdc++.h>
using namespace std;

int main()
{
  multiset<int> ms;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    ms.insert(x);
  }
  int q;
  cin >> q;
  while (q--)
  {
    int operate, key;
    cin >> operate >> key;
    if (operate == 1)
    {
      ms.insert(key);
    }
    else if (operate == 2)
    {
      auto it = ms.find(key);
      if (it != ms.end())
      {
        ms.erase(it);
      }
    }
    else // operate == 3
    {
      if (ms.find(key) != ms.end())
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }

  return 0;
}