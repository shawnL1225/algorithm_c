#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adjList[n]; 
    for(int i=0;i<m;i++){  //build graph
        int p1, p2;
        pair<int, int> p;
        cin >> p1 >> p2 >> p.first; //first weight, sec pointIdx
        p.second = p2;
        adjList[p1].push_back(p);
        p.second = p1;
        adjList[p2].push_back(p);
    }
    int dis[n];
    bool walked[n] = {0};
    int queA, queB;
    cin >> queA >> queB;

    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[queA] = 0;

    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pair<int, int> p(0,queA);
    pq.push(p);

    while(!pq.empty()){
        //for(auto x : dis) cout << x<<' ';
        pair<int, int> point = pq.top();
        pq.pop();
        if(walked[point.second] == 1) continue;
        walked[point.second] = 1;
        for(auto x : adjList[point.second]){
            if(x.first+dis[point.second] < dis[x.second]){
                //cout << "push:" << x.second<<endl;
               
                dis[x.second] = x.first + dis[point.second];
                pq.push({dis[x.second],x.second});
                //cout << "first" << x.first << "d"<<dis[point.second]<<endl;
            }
        }
    }
    if(dis[queB] == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << dis[queB] << endl;
    



}