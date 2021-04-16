#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec[1001];
    
    int walked[10001] = {0};
    int n,m,a,b;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    
    queue<int> Q;
    cin >> a >> b;
    Q.push(a);
    
    
    walked[a] = 1;
    while(!Q.empty()){
        int num = Q.front();
        Q.pop();
        for(auto x:vec[num]){
            if(walked[x] == 0){
                Q.push(x);
                walked[x] = walked[num]+1;
            }
        }
    }   
    if(walked[b] > 0) cout << "Yes";
    else cout << "No";
    
}