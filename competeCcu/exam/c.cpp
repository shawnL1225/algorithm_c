#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    lint a, b;
    cin >> a >> b;
    lint arr[a+1],num;
    arr[0] = 0;
    for(int i=1;i<=a;i++){
        cin >> num;
        arr[i] = arr[i-1]+num;
    }
    for(int i=0;i<b;i++){
        lint l,r,sum=0;
        cin >> l >> r;
        sum = arr[r] - arr[l-1];
        cout << sum*sum << endl;

    }

    return 0;
}