#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num;
    cin >> n;
    vector<int> arr;
    
    for(int i=0;i<n;i++){
        cin >> num;
        int p = lower_bound(arr.begin(),arr.end(),num)- arr.begin();
        // cout << p <<' ';
        if(p >= arr.size())
            arr.push_back(num);
        else
            arr[p] = num;
    }
    cout << arr.size();
}