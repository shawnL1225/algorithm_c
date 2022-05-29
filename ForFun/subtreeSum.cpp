#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int c[100005];
lint sum[100005];
vector<int> adj[100005];

lint DFS(int v){
  
  sum[v] = c[v];
  for(auto neb : adj[v]){
    if(sum[neb] == -1)
      sum[v] += DFS(neb);
  }
  return sum[v];
}
int main(){
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) cin >> c[i];
  for(int i=0;i<n-1;i++){
    int v1, v2;
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
  memset(sum, -1, sizeof(sum));
  DFS(1);
  for(int i=1;i<=n;i++) cout << sum[i] << ' ';
  


  return 0;
}