#include<bits/stdc++.h>
using namespace std;
int n,Len,num;
int table[505][505];
vector<int> arr;
int DP(int L, int R){
    if(L>=R-1){
        table[L][R] = 0;
    }
    if(table[L][R] == -1){
        int min = 0x3f3f3f3f;
        int value;
        for(int i=L+1;i<R;i++){
            value = DP(L,i) + DP(i,R);
            if(value < min) min = value;
        }
        table[L][R] = min + arr[R] - arr[L];
    }
    
    return table[L][R];
}
int main(){
    cin >> n >> Len;
    arr.push_back(0);
    for(int i=0;i<n;i++){
        cin >> num;
        arr.push_back(num);
    }
    arr.push_back(Len);

    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            if(j>i) table[i][j] = -1;
            else table[i][j] = 0;
        }
    }
    cout << DP(0,n+1) <<endl;

}