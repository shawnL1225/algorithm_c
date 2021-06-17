#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int ct[10000];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    vector<string> dict;

    for(int i=0;i<n;i++){
        cin >> s;
        if(s[s.size()-1] == ')') s = s.copy()
        for(int j=0; j<dict.size();j++){
            if(dict[j] == s){
                cout << s <<'(' << ct[j] <<')' << endl;
                ct[j]++;
                break;
            }
        }

        dict.push_back(s);
        ct[dict.size()-1] = 1;
        cout << s <<endl;
    }


    return 0;
}