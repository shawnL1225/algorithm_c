#include <bits/stdc++.h>
using namespace std;
int arr[(unsigned)1e7] = {0};
int main(){
    int n, m;
    cin >> n >> m;
    int num, num2;
    for(int i=1;i<=n;i++)
    {
        cin >> num;
        arr[i] = num + arr[i-1];
    }

    for(int i=0;i<m;i++){
        cin >> num >> num2;
        cout << arr[num2] - arr[num-1] << endl;
    }
    

    
}