#include <bits/stdc++.h>
using namespace std;
int w[1002], v[1002], table[1002][1002];
int DP(int wei, int item){
    if(wei < 0) return -1e9;
    if(item == 0) return 0;

    if(table[wei][item]) return table[wei][item];
    
    return table[wei][item] = max(
        DP(wei - w[item], item-1) + v[item],
        DP(wei, item-1)
    );
}
int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }

    
    cout << DP(m,n)<<endl;
    // for(int i=0;i<=m;i++){
    //     for(int j=0; j<=n; j++){
    //         cout << table[i][j]<<' ';
    //     }
    //     cout << endl;
    // }
}