#include <bits/stdc++.h>
using namespace std;
int n,x,moveT=0;
string s;

bool arrive(long long int day){
    long long int step = 0;
    step += day/n * moveT;

    for(int i=0; i<day%n; i++){
        if(s[i] == 'E') step +=2;
    }
    //cout << day << "step" << step <<endl;
    return step >= x;
}


int main(){
    cin >> n >> s >> x;
    for(int i=0;i<n;i++){
        if(s[i] == 'E') moveT+=2;
    }
    if(moveT == 0){
        cout << -1;
        return 0;
    }
    
    long long int left = -1;
    long long int right =  LLONG_MAX;
    while(left < right-1){
        long long int mid = (left+right)/2;
        if(arrive(mid)){
            right = mid;
        }
        else {
            left = mid;
        }
        
    }
    cout << right << endl;
}0