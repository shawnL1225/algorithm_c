#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int n,m;
int u,v;
vector<int> adj[100005], trace;
int visited[100005];
bool suc=0;
int dfs(int v, int prev){
  if(suc) return 0;
  trace.push_back(v);
  visited[v] = 1;
  for(auto x: adj[v]){
    if(x == prev) continue;
    if(visited[x] == 0){
       
      dfs(x, v);
      
    }else if(visited[x] == 1 && trace.size()>2){
      suc = 1;
      cout << trace.size() << endl;
      for(auto nei : trace) {
        
        cout << nei << ' ';
        }
      return 0;
    }
  }
  trace.pop_back();
  return 0;
}
int main(){
  
  cin >> n >> m;
  
  for(int i=0;i<m;i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=0;i<n;i++){
    trace.clear();
    memset(visited, 0, sizeof(visited));
    dfs(i, -1);
    if(suc) break;
  }
  
  if(!suc) cout<<"IMPOSSIBLE\n";


  


  return 0;
}