#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int rec(int n){
    if(n==0 || n==1) return n+1;
    return rec(n-1) + rec(n/2);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n)
        cout << rec(n) << endl;


    return 0;
}