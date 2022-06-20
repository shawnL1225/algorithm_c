#include<bits/stdc++.h> 
using namespace std;
int main(){
    int a;
    while(cin >> a){
       printf("%d days\n", a/(60*60*24));
       a%=(60*60*24);
       printf("%d hours\n", a/(3600));
       a%=3600;
       printf("%d minutes\n", a/60);
       a%=60;
       printf("%d seconds\n", a);

      cout << a/(60*60*24) << " days\n";
       a%=(60*60*24);
       cout << a/3600 << " hours\n";
       a%=3600;
       cout << a/60 << " minutes\n";
       a%=60;
       cout << a << " seconds\n";
    }
    
        
}