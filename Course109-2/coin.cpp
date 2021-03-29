#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, money;
    cin >> n; 
    int coin[n];
    for(int i=0;i<n;i++)
        cin >> coin[i];

    cin >> money;
    int arr[money+1]; 
    arr[0] = 0;
    for(int i=1; i<=money; i++){
        arr[i] = 0x3f3f3f3f;
        for(int j=0;j<n;j++){
            if(i>=coin[j] && arr[i - coin[j]] +1 < arr[i])
                arr[i]  = arr[i-coin[j]]+1;
        }
    }
    
    if(arr[money] == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << arr[money] << endl;
}