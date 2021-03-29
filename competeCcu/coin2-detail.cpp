#include <bits/stdc++.h>
using namespace std;
int ctEach[1000005][21];



int MYmin(int a, int b, int type, int place, int to){
    if(a<b){ //換大面額較好時
        for(int i=0;i<21;i++)
            ctEach[place][i] = ctEach[to][i];
            
        ctEach[place][type] +=1;
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
            arr[j] = MYmin(arr[j-num]+1, arr[j], i, j, j-num);
        }
        
    }
    if(arr[money] == 0x3f3f3f3f)
        cout << -1 << endl;
    else{
        cout << arr[money] << endl;

        for(int i=0;i<n;i++){
            cout << ctEach[money][i] << ' ';
        }

    }
}
       

    