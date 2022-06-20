#include<bits/stdc++.h> 
using namespace std;
int main(){
    int a;
    while(cin >> a){
        if(a>31)cout << "Value of more than 31\n";
        else{
            cout << (1<<a) << endl;
        }
    }
    
        
}