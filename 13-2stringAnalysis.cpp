#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ct[200] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        ct[s[i]]++;
    }
    for (int i = 0; i < 150; i++)
    {
        if (ct[i] > 0)
        {
            cout << (char)i << ' ' << ct[i] << endl;
        }
    }
}