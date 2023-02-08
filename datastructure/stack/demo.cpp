#include <stack>
#include <string>
#include <iostream>
using namespace std;

// convert integer positive number to binary number
std::string stackBin(int n)
{
  string s;
  stack<char> st;
  while (n > 0)
  {
    st.push(n % 2 + '0');
    n /= 2;
  }
  while (!st.empty())
  {
    s = s + st.top();
    st.pop();
  }
  return s;
}

int main()
{
  char ch;
  ch = 12 + '0';
  cout << ch;
  return 0;
}
