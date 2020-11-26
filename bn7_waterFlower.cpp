#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i=0;i<=9;i++)
    {
        cout << i <<endl;
    }
    for(int i=10;i<=99;i++)
    {
        int sum=0,num=i;
        while(num!=0){
            
            sum +=(num%10)*(num%10);
            num/=10;
        }
        if(sum == i) cout << i <<endl;
    }
    for(int i=100;i<=990;i++)
    {
        int sum=0,num=i;
        while(num!=0){
            
            sum +=(num%10)*(num%10)*(num%10);
            num/=10;
        }
        if(sum == i) cout << i <<endl;
    }
}