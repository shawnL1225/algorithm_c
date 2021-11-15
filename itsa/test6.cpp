#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n){
        if(n<3) cout << "Winter\n";
        else if(n<6 ) cout << "Spring\n";
        else if(n<9 ) cout << "Summer\n";
        else if(n<12 ) cout << "Autumn\n";
        else if(n<13 ) cout << "Winter\n";
    }
    


    return 0;
}