#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n,t;
int arr[200000];
bool isable(ll m)
{
    int ct=0;
    int cur_h=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]> cur_h+m)
    }
}
int main(){
    
    cin >> n >> t;
    
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    ll l = 0,r = (ll)1e16;;

    ll m = (l+r)/2;
    if(isable(m)) r = m;
    else l = m;
}