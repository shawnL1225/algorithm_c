#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int n, k,arr[11];
set<int> s;
int ct(int num){
    int ct=0;
    for(auto it = s.begin(); it!=s.end();it++){
        if(*it > num) ct++;
    }
    return ct;
}
void dfs(int ind, int ctk ){

    if(ind == n+1 && ctk == k){
        for(int i=1;i<=n;i++) cout << arr[i] << ' ';
        cout << endl;
        return;
    }
    if(ctk > k || ind > n) return;

    for(int i=1; i<=n; i++){
        if(s.count(i) == 0){
            int newCtk = ctk + ct(i);
            arr[ind] = i;
            s.insert(i);
            
            dfs(ind+1, newCtk);

            arr[ind] = 0;
            s.erase(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    dfs(1,0);


    return 0;
}