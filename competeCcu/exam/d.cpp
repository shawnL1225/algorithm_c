#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

vector<int> v[6];
int total[6];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a, b, c, ans = 0;
    bool suc = 1;


    for(int i=0;i<n;i++){
        cin >> a ;
        
        if(a == 2){

            cin >> b >> c;
            
            total[b]= total[b] + c;
            

            v[b].push_back(c);
            // cout << total[b] << endl;
            
        }
        else if(a == 1){
            ans = 0;
            int abi[6];
            for(int j=1;j<=5;j++){
                sort(v[j].begin(), v[j].end(), greater<>());
                cin >> abi[j];

                if(total[j] < abi[j] ){
                  suc = 0; break;
                }
                
                int p = lower_bound(v[j].begin(),v[j].end(), abi[j]) - v[j].begin();
                p++;
                ans = p;
                cout << ans << endl;
            } 
            
        }
    }
    if(suc == 0) cout << -1;
    else cout << ans;


    return 0;
}