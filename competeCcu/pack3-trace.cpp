#include <bits/stdc++.h>
using namespace std;
int w[1002], v[1002], table[100002][1002];
bool put[100002][1002];

int MYmax(int a, int b, int item, int wei){
    if(a > b){
        put[wei][item] = 1;
        return a;
    }else{
        return b;
    }
}
int DP(int wei, int item){
    if(wei < 0) return -1e9;
    if(item == 0) return 0;

    if(table[wei][item]) return table[wei][item];

    
    return table[wei][item] = MYmax(
        DP(wei - w[item], item-1) + v[item],
        DP(wei, item-1),
        item,
        wei
    );

     
}


int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }


    cout << DP(m,n)<<endl;

    vector<int> vec;
    for(int i=n, j=m; i>=1; i--){
        if(put[j][i]){
            vec.push_back(i);
            j-=w[i];
        }
    }
    int len = vec.size();
    cout << len << endl;

    for(int i = len-1; i>=0; i--)
        cout << vec[i]-1 << ' ';
    
    

    // for(int i=0;i<=m;i++){
    //     for(int j=0; j<=n; j++){
    //         cout << table[i][j]<<' ';
    //     }
    //     cout << endl;
    // }
}