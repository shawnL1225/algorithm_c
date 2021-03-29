#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q, num, a, b;
    cin >> n >> q;
    int arr[n];
    for(int i=1;i<=n;i++)
    {
        cin >> num;
        arr[i] = num + arr[i-1];
    }
    while(q--){
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << endl;
    }
}