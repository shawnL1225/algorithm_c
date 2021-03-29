#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, money;
    cin >> n >> money;

    int arr[money+1];
    memset(arr,0x3f3f3f3f,sizeof(arr));
    arr[0] = 0;
    
    int num;
    for(int i=0;i<n;i++){
        cin >> num;
        for(int j=num; j<=money; j++){
            arr[j] = min(arr[j-num]+1, arr[j]);
        }
        
    }
    if(arr[money] == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << arr[money] << endl;
}