#include <bits/stdc++.h>
using namespace std;
vector<string> v;
typedef long long lint;
bool comp(string a, string b){
    if(a[0] != b[0]) return a>b;
    a = a.substr(1);
    b = b.substr(1);
    return atoi(a.c_str()) > atoi(b.c_str());
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s, card;
    stringstream ss;
    cin >> n;
    cin.ignore();


    for(int i=0;i<n;i++){
        getline(cin, s);
        ss << s;
        while(ss >> card){
            v.push_back(card);
        }

        sort(v.begin(),v.end(),comp);
        for(int j=0;j<v.size()-1;j++){
            cout << v[j] << ' ';
        }
        
        cout << v[v.size()-1];
        if(i != n-1)
            cout << endl;


        ss.clear();
        v.clear();

    }


    return 0;
}