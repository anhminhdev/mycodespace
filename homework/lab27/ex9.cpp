// #include <iostream>
// #include <string>
// using namespace std;

// // Sort character in string
// void sortCharacter(string &s)
// {
//   int len = s.length();
//   for (int i = 0; i < len - 1; i++)
//   {
//     for (int j = i + 1; j < len; j++)
//     {
//       if (s[i] > s[j])
//       {
//         swap(s[i], s[j]);
//       }
//     }
//   }
// }

// bool isAnagram(string s1, string s2)
// {
//   if (s1 == s2)
//   {
//     return true;
//   }
//   else
//     return false;
// }

// int main()
// {
//   string s1, s2;
//   cin >> s1 >> s2;
//   sortCharacter(s1);
//   sortCharacter(s2);
//   if (isAnagram(s1, s2))
//     cout << "YES";
//   else
//     cout << "NO";
//   return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string s1, string s2)
{
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  return (s1 == s2);
}

int main()
{

  return 0;
}