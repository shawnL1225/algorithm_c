#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int main(){
    
    int n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        lint ma = max(a,b);
        lint ans;
        if(ma%2 == 1){
            if(b == ma){
                ans = ma*ma - (a-1);
            }else{
                ans = (ma-1)*(ma-1) + b;
            }
        }else{
            if(a == ma){
                ans = ma*ma - (b-1);
            }else{
                 ans = (ma-1)*(ma-1) + a;
            }
        }

        cout << ans << endl;
    }
    
}   