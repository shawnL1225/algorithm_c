#include<bits/stdc++.h>
using namespace std;
struct s{
    int node;
    int r;
};
bool comp(s a, s b){
    return a.r< b.r;
}
int main(){
    vector<s> v[1002];
    int n, m;
    cin >> n >> m;
    int a;
    while(n--){
        s s1;
        cin >>a>>
         s1.node >> s1.r;
        v[a].push_back(s1);
        
    }
    int k;
    cin >> k;
    while(k--){
        cin >> a;
        if(v[a].size()==0) {
            cout << -1 << endl;
            continue;
        }

        sort(v[a].begin(), v[a].end(),comp);
        cout << v[a][0].node <<' '<< v[a][0].r;
        cout <<'\n';
    }

}