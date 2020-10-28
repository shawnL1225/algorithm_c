#include <bits/stdc++.h>
using namespace std;
vector<int> L,R,S;
int main(){
    int n,left,right,k;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> left >> right >> k;

    for(int i=left;i<=right;i++){
        if(arr[i] < arr[k])
            L.push_back(arr[i]);
        else if(arr[i] > arr[k])
            R.push_back(arr[i]);
        else 
            S.push_back(arr[i]);
    }

    for(int i=0;i<left;i++)
        cout << arr[i]<<' ';
    for(int i=0;i<L.size();i++)
        cout << L[i] << ' ';
    for(int i=0;i<S.size();i++)
        cout << S[i] << ' ';
    for(int i=0;i<R.size();i++)
        cout << R[i] << ' ';
    for(int i=right+1;i<n;i++)
        cout << arr[i] << ' ';
}