#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string str;
vector<string> res;

void solve(int i, string temp)
{
  res.push_back(temp);
  for (int j = i; j < str.length(); j++)
  {
    temp += str[j];
    solve(j + 1, temp);
    temp.pop_back();
  }
}

int main()
{
  cin >> str;
  solve(0, "");
  sort(res.begin(), res.end(), [](string a, string b)
       {
    if (a.length() != b.length())
      return a.length() > b.length();
    return a < b; });

  for (auto s : res)
    cout << s << endl;
  return 0;
}
