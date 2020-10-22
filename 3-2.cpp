#include <bits/stdc++.h>
using namespace std;
struct P {
    long long int x;
    int y;
};
int main() {
    P orin, dest, now, vd, vn;
    cin >> orin.x >> orin.y >> dest.x >> dest.y>>now.x >> now.y;
    vd.x = dest.x-orin.x; vd.y = dest.y-orin.y;
    vn.x = now.x-orin.x; vn.y = now.y-orin.y;
    long long int z = vd.x*vn.y-vd.y*vn.x;
    if(z==0) cout << "GREAT";
    else if(z>0) cout <<"LEFT";
    else cout << "RIGHT";

}