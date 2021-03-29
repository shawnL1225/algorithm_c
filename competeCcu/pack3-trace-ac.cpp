#include <bits/stdc++.h>
using namespace std;
int w[1002], v[1002], table[100002][2];
bool put[100002][1002];

int MYmax(int a, int b, int item, int wei){
    if(a > b){
        
        return a;
    }else{
        put[wei][item] = 1;
        return b;
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }

    for(int j=1;j<=n;j++){
        for(int i=1; i<=m; i++){
            if(i >= w[j])
                table[i][j%2] = MYmax(
                    table[i][(j-1)%2],
                    table[i-w[j]][(j-1)%2] + v[j],
                    j,i
                );
            else 
                table[i][j%2] = table[i][(j-1)%2];
        }


        
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0; j<=1; j++){
    //         cout << table[i][j]<<' ';
    //     }
    //     cout << endl;
    // }

    
    cout << table[m][n%2] << endl;
    
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
    
}