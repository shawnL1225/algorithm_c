#include <bits/stdc++.h>
using namespace std;
int n,k;
int ct[25];
typedef long long lint;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    
    string s,ans="";
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<k;j++)
        {
            if(s[j]=='1') ct[j]+=1;
        }
    }
    for(int i=0;i<k;i++){
        if(n%2==0){
             if(ct[i] >= n/2) ans+="0";
            else ans+="1";
        }
        else{
            if(ct[i] > n/2) ans+="0";
            else ans+="1";
        }
        
    }

    cout << ans;


    return 0;
}