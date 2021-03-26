#include<bits/stdc++.h>
using namespace std; 
long long int pow3(long long int a, long long int b,long long int c)
{
    if(b==0) return 1;
    if(b%2==0){
        return (pow3(a,b/2,c) * pow3(a,b/2,c)) %c;
    }else {
        return (pow3(a,b/2, c) * pow3(a,b/2, c) * a) %c;
    }
}
int main(){
    long long int a, p;
    cin >> a >> p;
    long long int ap2 = pow3(a, p-2, p);
    cout << ap2<<endl;

    
}
