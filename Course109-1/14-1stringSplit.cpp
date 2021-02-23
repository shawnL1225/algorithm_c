#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i] == ',' || s[i]==' ' || s[i] == '/') cout << '\n';
        else cout << s[i];
    }
}