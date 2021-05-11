#include <bits/stdc++.h>
using namespace std;
int ctEach[20][1000005];
int mymin(int a, int b, int type, int from, int to){
    if(a<b){
        for(int i=0;i<20;i++){ //將所有j價格的硬幣分別個數 改成 j-num的硬幣分別個數
            ctEach[i][from] = ctEach[i][to];
        }
        ctEach[type][from] +=1; //因為第type個的硬幣有選 所以再加一

        return a;
    }else{
        return b;
    }
}
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
            arr[j] = mymin(arr[j-num]+1, arr[j], i, j, j-num);
        }
        
    }
    if(arr[money] == 0x3f3f3f3f)
        cout << -1 << endl;
    else{
        cout << arr[money] << endl;

        for(int i=0;i<n;i++){
            cout << ctEach[i][money] << ' ';
        }

    }
}
       

    