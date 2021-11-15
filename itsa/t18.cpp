#include <bits/stdc++.h>
using namespace std;
string table = "1234567890-==!@#$%^&*()_++qwertyuiop[]\\\\{}||asdfghjkl;'':\"\"zxcvbnm,.//<>??";
typedef long long lint;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    getline(cin, s);
    int len = s.length();

    for(int i=0;i<len;i++){
        char c = tolower(s[i]);
        int k = table.find(c);
        cout << table[k+1];


    }

    return 0;
}