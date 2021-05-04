#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

int r[300000], sz[300000];

void init(){
    for(int i=0;i<300000;i++) {r[i] = i;sz[i] = 1;}
}
int find(int x){
    if(x == r[x]) return x;
    return r[x] = find(r[x]);
}
void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(sz[x] > sz[y]) swap(x, y);
    r[x] = r[y];
    sz[y] += sz[x];
    //sz[x] = 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    init();
    int u, v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        Union(u, v);
    }
    cin >> u >> v;
    if(find(u) == find(v)) cout << "Yes";
    else cout << "No";
    


    return 0;
}