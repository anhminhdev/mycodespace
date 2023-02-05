#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {9, 23, 1, 3, 2004, 7, 5};
    sort(v.begin(), v.end(), greater<>());
    for (auto x : v)
    {
        cout << x << ' ';
    }

    return 0;
}