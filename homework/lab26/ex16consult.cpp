#include <iostream>
using namespace std;

int main()
{

  int n, first[2000], second[2000], s;
  int sum = 0;
  cin >> n;
  for (int i = 1; i < n + 1; i++)
  {
    cin >> first[i];
  }
  // in the second array exchange the actual entries in the sequence with their indices
  // that way we can quickly check if a pair is inverted
  for (int i = 1; i < n + 1; i++)
  {
    cin >> s;
    second[s] = i;
  }
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = i + 1; j < n + 1; j++)
      // i < j always
      // when we check the indices of the respective entries in the second array
      // the relationship should stay otherwise we have an inversion
      if (second[first[i]] >= second[first[j]])
        sum++;
  }
  cout << sum;
  return 0;
}