#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n, m;
    cin >> n >> m;
    int arr[n+5][m+5];

    memset(arr,0,sizeof(arr));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> arr[i][j];
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((arr[i][j] > arr[i-1][j]) && arr[i][j] > arr[i+1][j]  && 
            arr[i][j] > arr[i][j-1] && arr[i][j] > arr[i][j+1])
                cout << arr[i][j] <<endl;
        }
    }
        
  
  
  
    
}