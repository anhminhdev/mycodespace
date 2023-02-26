#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isBeautifulNumber(ll n)
{
  if (n < 0)
    n *= -1;
  string s = to_string(n);
  for (int i = 0; i < s.size(); i++)
  {
    if ((i + 1) % 2 != (s[i] - '0') % 2)
      return false;
  }
  return true;
}

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  ll n;
  cin >> T;
  while (T--)
  {
    cin >> n;
    if (isBeautifulNumber(n))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
