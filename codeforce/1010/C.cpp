#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
vector<array<int,2>> canvas;
vector<int> toBin;
vector<int> ans;
int ctPin[10000];
set<int> s;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, pNum;
    cin >> n;
    for(int i=0;i<n;i++){
        array<int,2> can;
        cin>> can[0] >> can[1];
        canvas.push_back(can);
        toBin.push_back(can[1]);

    }
    cin >> pNum;
    for(int i=0;i<pNum;i++){
        int pin;
        cin >> pin;
        s.insert(pin);
        auto idx = lower_bound(toBin.begin(), toBin.end(), pin) - toBin.begin();
        

        if(pin >= canvas[idx][0] && pin <= canvas[idx][1])
            ctPin[idx]++;
        if(pin == canvas[idx +1][0]){
            ctPin[idx+1]++;
        }
    }
    for(int i=0;i<n;i++){
        if(ctPin[i] > 2) {
            cout << "impossible";
            return 0;
        }
        while(ctPin[i] < 2){
            int newP = canvas[i][1];
            if(canvas[i][1] == canvas[i+1][0] && ctPin[i+1]>1) newP--;
            while(s.count(newP)){
                newP--;
            }
            ans.push_back(newP);
            s.insert(newP);
            ctPin[i]++;
            if(newP >= canvas[i+1][0]){
                ctPin[i+1]++;
            }
        }
    }
    cout << ans.size() << endl;
    for(auto x:ans) cout << x << ' ';


    return 0;
}