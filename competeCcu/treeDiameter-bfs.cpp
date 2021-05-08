#include<bits/stdc++.h>
using namespace std;
vector<int> vec[300000];
int walked[300000];
int parent[300000];
deque<int> Q;
void BFS(){
    while(!Q.empty()){
        int num = Q.front();
        Q.pop_front();
        for(auto x:vec[num]){
            if(walked[x] == 0){
                Q.push_back(x);
                walked[x] = walked[num]+1;
                parent[x] = num;
            }
        }
    }
}
int main(){
    
    int n,m,a,b;
    cin >> n;
    m = n-1;
    while(m--){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    

   
    memset(walked,0,sizeof(walked));
    Q.push_back(a);
    walked[a] = 1;
    BFS();
    
    //找最遠節點
    int max = -1, node;
    for(int i=1;i<=n;i++){
        if(walked[i] > max){
            max = walked[i];
            node = i;
        }
    }

    Q.clear();memset(walked,0,sizeof(walked));

    
    walked[node] = 1;
    Q.push_back(node);
    BFS();

    //找新節點最遠的長和節點
    max = -1;
    for(int i=1;i<=n;i++){
        if(walked[i] > max){
            max = walked[i];
            node = i;
        }
    }

    // cout << max-1; //diameter

    //center
    for(int i=0;i<(max-1)/2;i++){
        int k = parent[node];
        node = k;
    }
    if((max-1) % 2 == 1){
        int node2= parent[node];
        cout << min(node2, node);
    }else{
        cout << node;
    }


    

    
    
}