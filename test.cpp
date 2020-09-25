#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n = 3, m=4;
    int arr[n][m];
    int a[8];

    memset(arr,6,sizeof(arr));

    
    for(int i=0;i<8;i++)
        cout << a[i] << ' ';

    cout << "\n\n";

    for(int i=0;i<n;i++){
        for(int j=0; j<m;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
        
}