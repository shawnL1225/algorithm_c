#include<bits/stdc++.h>
using namespace std;
int n,x;
vector<int>v;
int ind[200005];
int rem[200005];
long long int cnt=0;
int main(){
    memset(rem, -1, sizeof(rem));
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;

    
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        ind[x] = i;
    }
    for(int i=1;i<n;i++){
        auto it = ind[i];
        cnt += it;
        rem[]
        while()
        

    }
    cout<<cnt<<'\n';
}