#include <bits/stdc++.h>
using namespace std;
int arr[300];
typedef long long lint;

int rec(int l, int r){
    if(l==r) return arr[l];
    if(l>r) return 0;
    int num = arr[l];
    return max(num+rec(l+2, r), rec(l+1,r));
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << rec(0,n-1);

    return 0;
}