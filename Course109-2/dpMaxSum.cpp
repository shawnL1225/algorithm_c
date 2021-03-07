#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main(){
    int n, num, left=1, right, max=-1e8, ctseg=1;
    cin >> n;
    int leftSeg=1;

    bool inSeg=1;
    for(int i=1;i<=n;i++){
        cin >> num;
        arr[i] = arr[i-1] + num;

        if(arr[i] > max){
            max = arr[i];
            left = leftSeg;
            right = i;
        }

        if(arr[i]<0){
            arr[i] = 0;
            inSeg = 0;
        }else{
            if(!inSeg){
                leftSeg = i;
                inSeg = 1;
            }
        }
    }
    cout << left << ' ' << right << endl;
    cout <<max <<endl;
}