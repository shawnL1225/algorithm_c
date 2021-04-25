#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

void solve() {
    int n;cin >> n;
    char map[n][n];
    vpi p;
    F0R(i,n)
        F0R(j,n){
            cin >> map[i][j];
            if(map[i][j] == '*'){
                pair<int, int> po(i,j);
                p.push_back(po);
            }
        }
    if(p[0].first == p[1].first){
        map[(p[0].first+1)%n][p[0].second] = '*';
        map[(p[0].first+1)%n][p[1].second] = '*';
    }else if(p[0].second == p[1].second){
        map[p[0].first][(p[0].second+1)%n] = '*';
        map[p[1].first][(p[0].second+1)%n] = '*';
    }else{
        map[p[0].first][p[1].second] = '*';
        map[p[1].first][p[0].second] = '*';
    }
            
     F0R(i,n){
        F0R(j,n){
            cout << map[i][j];
        }
        cout << endl;
     }
        
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
