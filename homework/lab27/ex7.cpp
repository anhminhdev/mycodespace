#include <bits/stdc++.h>
using namespace std;

void reverseWord(string s)
{
  stack<char> st;
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] != ' ')
    {
      st.push(s[i]);
    }
    else
    {
      while (st.empty() == false)
      {
        cout << st.top();
        st.pop();
      }
      cout << " ";
    }
  }
  // Since there may not be space after last word.
  while (st.empty() == false)
  {
    cout << st.top();
    st.pop();
  }
}

int main()
{
  string s;
  getline(cin, s);

  reverseWord(s);
  return 0;
}