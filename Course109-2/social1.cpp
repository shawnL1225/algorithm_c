#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> pMap;
    int pn,cn;
    cin >> pn;
    string name[pn];
    for(int i=0;i<pn;i++){
        cin >> name[i];
        pMap[name[i]] = i;
    }
    bool net[pn][pn];
    memset(net,0,sizeof(net));


    cin >> cn;
    string cmd, s1, s2;
    for(int i=0;i<cn;i++){
        cin >> cmd;
        if(cmd == "MakeFriend"){
             cin >> s1 >> s2;
            net[pMap[s1]][pMap[s2]] = 1;
            net[pMap[s2]][pMap[s1]] = 1;
        }
        else if(cmd == "ListFriend"){
            cin >> s1;
            for(int j=0;j<pn;j++)
            {
                if(net[pMap[s1]][j])
                    cout << name[j] << ' ';
            }
            cout << endl;
        }
       
    }


}
