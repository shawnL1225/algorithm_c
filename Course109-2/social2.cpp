#include <bits/stdc++.h>
using namespace std;

vector<int> net[505];
int n,conT,queT,cmdt=0;
bool connected = 0;
bool isWalk[505];
int dfs(int now,int dest){
    // cout << now << endl;
    isWalk[now] = 1;
    int len = net[now].size(); 

    for(int i=0;i<len;i++)
    {
        if(connected) break;
        if(!isWalk[net[now][i]]) {
            if(dest == net[now][i]) {
                connected = 1;
                return 0;
            }
            else
                dfs(net[now][i],dest);
        }

    }
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    cin >> n;
    cin >> conT;
    int p1,p2;
    for(int i=0;i<conT;i++){
        cin >> p1 >> p2;
        net[p1].push_back(p2);
        net[p2].push_back(p1);
    }
    cin >> queT;

    for(int i=0;i<queT;i++){
        for(int j=0;j<502;j++) isWalk[j] = 0;
        connected = 0;
        
        cin >> p1 >> p2;
        
        dfs(p1,p2);
        
        if(connected) cout << "Yes\n";
        else cout << "No\n";
        

    }
}

