#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        int obj[a], team[b]; 
        for(int i=0;i<a;i++) cin >> obj[i];
        for(int i=0;i<b;i++) cin >> team[i];
        sort(obj, obj+a);
        sort(team, team+b);
        int ans=0;
        int pE=0,pT=0;
        for(;pT<b && pE<a;){
            if(team[pT] >= obj[pE]){
                ans+=team[pT];pT++; pE++;
            }else{
                pT++;
            }
        }
        if(pE<a-1)
            cout << -1 <<endl;
        else
            cout << ans << endl;

    }
}