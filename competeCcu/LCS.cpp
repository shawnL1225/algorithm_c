#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main(){
    string s, t;
    cin >> s >> t;
    s = "0"+s;
    t = "0"+t;
    int sLen = s.size();
    int tLen = t.size();
    for(int i=1;i<sLen;i++){
        for(int j=1;j<tLen;j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1] +1 ;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // for(int i=0;i<s.size();i++){
    //     for(int j=0;j<t.size();j++){
    //         cout << dp[i][j]<<' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[sLen-1][tLen-1] << endl;
    
}