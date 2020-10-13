#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m,input;
    cin >> n;
    n++;
    vector<int> a;
    for(int i=0;i<n;i++){
         cin >>input;
        a.push_back(input);
    }
       
    cin >> m;
    m++;
    vector<int> b;
    for(int i=0;i<m;i++){
        cin >> input;
        b.push_back(input);
    }
        
    
    int iv = n-m;
    if(iv < 0)
    {
        for(int i=0;i<abs(iv);i++)
            a.insert(a.begin(),0);
    }
    else
    {
        for(int i=0;i<abs(iv);i++)
            b.insert(b.begin(),0);
    }


    for(int i=0;i<max(n, m);i++)
    {
        cout << a[i]+b[i] << ' ';
    }

  
  
  
    
}