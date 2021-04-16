#include <bits/stdc++.h>
using namespace std;
int sum[100000], arr[100000] ;
int main(){
    int n, l;
    cin >> n >> l;
    int left = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        sum[i] = arr[i] + sum[i-1];

        if(sum[i] < l) {
            cout << -1 <<' ';
            continue;
        }

        while(sum[i] - sum[left+1] >= l) left++;
        cout << left+1 << ' ';

    }
    
}