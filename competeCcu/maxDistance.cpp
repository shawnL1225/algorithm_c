#include<bits/stdc++.h>
using namespace std;
typedef long long int lint;


int main(){
    string n;
    getline(cin, n);
    int n2=atoi(n.c_str());

    while(n2--){
        vector<lint> coo1, coo2;
        string s1;
        stringstream ss;
        getline(cin, s1);
        ss << s1;
        int num;
        while(ss>>num) coo1.push_back(abs(num));
        getline(cin, s1);
        ss.clear(); ss << s1;
        while(ss>>num) coo2.push_back(abs(num));
        
        sort(coo1.begin(),coo1.end());
        sort(coo2.begin(),coo2.end());
        double ans =0;
        int len = coo1.size();
        for(int i=0;i<len;i++){
            lint sqare = coo1[i]*coo1[i] + coo2[len-1-i]*coo2[len-1-i];
            ans += sqrt(sqare);
        }
        cout << (lint)ans <<endl;

    }
}