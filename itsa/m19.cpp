#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        double pay ;
        if(n >=1500){
           pay = n*0.9*0.79;
        }
        else if(n>800){
           pay = n*0.9*0.9;
        }
        else {
            pay = n*0.9;
        }
         cout << setprecision(1) << fixed << pay << endl;
    }
    
}