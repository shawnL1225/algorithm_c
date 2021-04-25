#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, t, arr[102],ct[102] = {0}, num;
    cin >> n;
    while(n--){
        cin >> t;
        for(int i=0;i<t;i++){
            cin >> arr[i];
            ct[arr[i]]++;
        }
        for(int i=1;i<t;i++){
            if(arr[i] != arr[i-1]){
                if(ct[arr[i]] == 1)
                    cout << i+1 << endl;
                else
                    cout << i <<endl;

                ct[arr[i]] = 0;ct[arr[i-1]] = 0;
                break;      
            }
        }
    }
}