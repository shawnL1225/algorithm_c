#include <iostream>
#include <cmath>
using namespace std;
struct P {
    double x;
    double y;
};
int main() {
    P orin, dest, now, vd, vn;
    cin >> orin.x >> orin.y >> dest.x >> dest.y>>now.x >> now.y;
    vd.x = dest.x-orin.x; vd.y = dest.y-orin.y;
    vn.x = now.x-orin.x; vn.y = now.y-orin.y;
    double z = vd.x*vn.y-vd.y*vn.x;
    if(fabs(z) < 1e-6) cout << "Collinear";
    else cout << "General Position";

}