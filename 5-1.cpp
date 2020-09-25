#include<iostream>
using namespace std;
int main()
{
    int i=0,n,a[10005];

    cin >> n;
    while (n>0)  
    {
        a[i] = n%2;  
        i = i+1;
        n = n/2;
    }


    for(; i > 0; i--){
        if(i%4==0) cout << ' ';
        cout << a[i-1];

        
    }
      

    return 0;
}