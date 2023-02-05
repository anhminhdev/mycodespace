#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s, delimiters;
  getline(cin, s);
  getline(cin, delimiters);

  int start = s.find_first_not_of(delimiters);
  while (start != string::npos)
  {
    int end = s.find_first_of(delimiters, start);
    if (end == string::npos)
      end = s.length();
    cout << s.substr(start, end - start) << endl;
    start = s.find_first_not_of(delimiters, end);
  }
  return 0;
}
