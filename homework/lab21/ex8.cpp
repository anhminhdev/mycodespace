/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

// ###INSERT CODE HERE -

bool isRepeat(string s)
{
    int len = s.length();
    string sub1 = s.substr(0, len / 2);
    int len2 = len - sub1.length();
    string sub2 = s.substr(len / 2, len2);
    if (sub1.compare(sub2) == 0)
        return true;
    else
        return false;
}

int main()
{
    string inputString;
    getline(cin, inputString);
    cout << isRepeat(inputString);
    return 0;
}
