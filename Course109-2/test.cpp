#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v[5];
    vector<int> com;
    v[0].push_back(1);
    v[0].push_back(1);
    v[3].push_back(1);
    v[3].push_back(0);
    com.push_back(1);
    com.push_back(0);
   
    if(v[0]==com)
        cout << "T";
    
}