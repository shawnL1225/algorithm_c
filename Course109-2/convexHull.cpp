#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

struct P{
    lint x;
    lint y;
    int id;
};

P leftTop;
vector<P> point;

lint cross(P o, P a, P b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
lint length2(P a, P b){
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}
bool comp_angle(P a, P b){
    lint c = cross(point[0], a, b);
    return c > 0 ||
            (c == 0 && length2(point[0], a) < length2(point[0], b));
    // if(a.x==leftTop.x && a.x == b.x){ //wrong
    //     return a.y > b.y;
    // }
    // if(a.x==leftTop.x){
    //     return true;
    // }
    // if(b.x==leftTop.x){
    //     return false;
    // }

    // if(a.y == b.y){
    //     if(a.y>0)
    //         return a.x>b.x;
    //     else 
    //         return a.x<b.x;
    // }
    // return a.y<b.y;
}

bool compare_position(P a, P b)
{
    return (a.x < b.x) || (a.x == b.x && a.y > b.y);
}

int main(){
    int n;
    cin >> n;
    
    vector<P> ans;
    P input;
    for(int i=0;i<n;i++){
        cin >> input.x >> input.y;
        input.id = i;
        point.push_back(input);
    }
    // leftTop = point[0];
    // for(int i=1;i<n;i++){
    //     if (point[i].x < leftTop.x){
    //         leftTop = point[i];
    //     }else if(point[i].x == leftTop.x){
    //         if(point[i].y > leftTop.y)
    //             leftTop = point[i];
    //     }
    // }
    swap(point[0], *min_element(point.begin(), point.end(), compare_position));
    sort(point.begin()+1, point.end(), comp_angle );
    point.push_back(point[0]);
    
    
    int m=0;
    for(int i=0;i<=n;i++){
        while(m>=2 && cross(ans[m-2],ans[m-1],point[i])<=0) {
            m--;
            ans.pop_back();
        }

        m++;
        ans.push_back(point[i]);

        
    }
    

    // for(auto x:point){
    //     cout << x.id <<' ';
    // }
    // cout << '\n';
    cout << ans.size() <<endl;
    for(auto x:ans){
        cout << x.id+1 <<' ';
    }

}