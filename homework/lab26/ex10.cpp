#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMax(int a[], int n, int k)
{
  int max = 0, index, b[10000], m = n - k + 1;
  // i=max store in v2
  vector<int> v1, v2;
  for (int i = 0; i <= n - k; i++)
  {
    int sum = 0;
    for (int j = i; j < i + k; j++)
    {
      sum += a[j];
    }
    b[i] = sum;
    if (max < sum)
    {
      max = sum;
      index = i;
    }
  }
  int id1 = index - k + 1;
  int id2 = index + k - 1;
  for (int i = 0; i < m; i++)
  {
    if (i < id1 || i > id2)
      v1.push_back(b[i]);
    else
      v2.push_back(b[i]);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  // for (int i = 0; i < v2.size(); i++)
  // {
  //     cout<<v2[i]<<" ";
  // }
  // cout<<endl;
  // for (int i = 0; i < v1.size(); i++)
  // {
  //     cout<<v1[i]<<" ";
  // }
  // cout<<endl;
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  for (int i = v2.size() - 1; i >= 0; i--)
  {
    if (v2[i] < v1.back())
    {
      max = v2[i + 1];
      break;
    }
  }
  return max;
}
int main()
{
  int n, k;
  int a[10000];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << findMax(a, n, k);
}