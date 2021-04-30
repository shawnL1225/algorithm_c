#include<bits/stdc++.h>
using namespace std;

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


struct ufds{
    int u, v, w;
} net[300000];

bool comp(ufds a, ufds b){
    return a.w < b.w;
}
int main(){
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> net[i].u >> net[i].v >> net[i].w;
    }    
    sort(net, net+m, comp);
    int ctEdge =0, totalW=0;
    for(int i=0, j=0; j<m && i<n-1;j++){
        if(find(net[j].u) == find(net[j].v) ) continue;

        Union(net[j].u, net[j].v); 
        // cout<<net[j].u<<' '<< net[j].v<<'\n';
        ctEdge++;
        totalW+=net[j].w;
        i++;

    }
    
    if(ctEdge == n-1) cout << totalW;
    else cout << -1;
    
}