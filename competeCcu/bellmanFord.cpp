#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    vector<pair<lint, lint>> node[n+5];
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int p1,p2,w;
        cin >> p1 >> p2 >> w;
        node[p1].push_back({p2,w});
    }
    bool change = true;
    int ctRound = 0;
    lint dis[1005];
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;

    while(change && ctRound <= n-1){
        change = false;
        ctRound++;
        for(int i=1; i<=n; i++){
            for(auto connect : node[i]){
                lint w = connect.second;
                lint id = connect.first;
                if(dis[i]+w < dis[id]){
                    change = true;
                    dis[id] = dis[i]+w;
                }
            }
        }
    }

    if(ctRound <= n-1){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}