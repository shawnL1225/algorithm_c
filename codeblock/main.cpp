#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

int arr[200005] = {0};
int dfs(int num){

    if(arr[num] != 0){
        return arr[num];
    }

    if(num<10){
        arr[num] = num;
        return num;
    }

    int newN=1, num2 = num;
    while(num != 0){
        newN *= num%10;
        num/=10;
    }

    arr[num2] = dfs(newN);
    return arr[num2];


}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int l,r,k;
    while(n--){
        int ct=0;
        cin >> l >> r >> k;
        for(int i=l;i<=r;i++){
            if(k == dfs(i)) ct++;
        }
        cout << ct << endl;
    }



    return 0;
}
