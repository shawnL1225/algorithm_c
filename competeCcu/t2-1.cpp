#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if(n==0) break;
        int enemy[n], team[n]; 
        for(int i=0;i<n;i++) cin >> enemy[i];
        for(int i=0;i<n;i++) cin >> team[i];
        sort(enemy, enemy+n);
        sort(team, team+n);
        int ans =0;
        for(int pE=0, pT=0;pT<n && pE<n;){
            // cout << pT << ' '<< ans<<endl;
            if(team[pT] > enemy[pE]){
                pT++; pE++; ans++;
                
            }else{
                pT++;
            }
        }
        cout << ans << endl;

    }
}