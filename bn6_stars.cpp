#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ox,oy,dx,dy,n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ox >> oy >> dx >> dy;

        int vx = abs(dx-ox), vy = abs(dy-oy);
        cout << __gcd(vx,vy) +1 <<endl;
    }

}
