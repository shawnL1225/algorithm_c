#include<bits/stdc++.h> 
using namespace std;
int gcd(int n1, int n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}
int main(){
    int a,b;
    while(cin >> a >> b){
        if (a<b) 
           cout << gcd(b,a) << endl;
        else
            cout << gcd(a,b) << endl;
    }
        
}