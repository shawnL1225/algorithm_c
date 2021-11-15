#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s){
        bool suc = 1;
        int len = s.length();
        for(int i=0;i<len;i++){
            if(s[i]!=s[len-1-i]){
                suc = 0;
                break;
            }
        }
        if(suc) cout << "YES\n";
        else cout << "NO\n";
        
    }


    return 0;
}