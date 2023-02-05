#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> startPosition(n);
  vector<int> speed(n);
  for (int i = 0; i < n; i++)
  {
    cin >> startPosition[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> speed[i];
  }

  int max_collision = -1;
  for (int i = 0; i < n; i++)
  {
    int collision = 1;
    for (int j = i + 1; j < n; j++)
    {
      if ((startPosition[i] - startPosition[j]) * (speed[i] - speed[j]) <= 0)
      {
        collision++;
      }
    }
    max_collision = max(max_collision, collision);
  }
  cout << max_collision << endl;
  return 0;
}