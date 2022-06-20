#include <bits/stdc++.h>
using namespace std;
vector<int> dependlist[5005];
vector<int> revDependlist[5005];
set<int> installed;
bool userinstall[5005];
int n, q;
int ct = 0;

void LIST(){
  cout << installed.size() <<' ';
  for(auto it = installed.begin();it!=installed.end();it++){
    cout << *it << ' ';
  }
  cout << endl;
}

void INSTALL(int v){
  for(auto x : dependlist[v]){
    if(!installed.count(x)){
      INSTALL(x);
    }
  }
  installed.insert(v);
  ct++;
}
void REMOVE(int v){
  bool hasOtherDepend = 0;
  for(auto y : revDependlist[v]){ // check can be remove
    if(installed.count(y)){
      hasOtherDepend = 1;
      break;
    }
  }
  if(!hasOtherDepend) {
    installed.erase(v);
    ct++;
    for(auto x : dependlist[v]){
      if(userinstall[x]) continue;
      REMOVE(x);
    }
  }

  
  
}
int main(){
 
  cin >> n >> q;

  for(int i=0;i<n;i++){
    int num, k;
    cin >> num;
    while(num--){
      cin >> k;
      revDependlist[k].push_back(i);
      dependlist[i].push_back(k);
    }
    
  }
  string state;
  int vertex;
  while(q--){
    cin >> state;
    if(state == "INSTALL"){
      ct = 0;
      cin >> vertex;
      userinstall[vertex] = 1;
      INSTALL(vertex);
      cout << ct << endl;
    }
    else if(state == "REMOVE"){
      ct = 0;
      cin >> vertex;
      userinstall[vertex] = 0;
      REMOVE(vertex);
      cout << ct << endl;
    }else{
      LIST();
    }
  }
  


  return 0;
}