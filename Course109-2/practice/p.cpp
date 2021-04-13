#include <bits/stdc++.h>
using namespace std;
vector<int> net[505], step;
bool walked[505];
bool connected = 0;
int DFS(int now, int dest){
    walked[now] = 1;
    int len = net[now].size();

    for(int i=0;i<len;i++){
        int p = net[now][i];
        if(!walked[p]){
            if(dest == p){
                connected = 1;
                return 1;
            }else{
                step.push_back(p);
                if(DFS(p,dest) == 1){
                    return 1;
                }
                step.pop_back();
                
            }
        }
    }
    return 0;
}
int main(){
    int n, conT, queT;
    cin >> n >> conT;
    int p1,p2;

    for(int i=0;i<conT;i++)
    {
        cin >> p1 >> p2;
        net[p1].push_back(p2);
        net[p2].push_back(p1);
    }

    cin >> queT;
    for(int i=0;i<queT;i++){
        cin >> p1 >> p2;
        memset(walked,0,sizeof(walked));
        connected = 0;
        step.clear();
        step.push_back(p1);
        DFS(p1, p2);
        step.push_back(p2);

        if(connected){
            for(int j=0;j<step.size();j++){
                cout << step[j] << ' ';
            }
        }
        else
            cout << -1 << endl;
    }

}