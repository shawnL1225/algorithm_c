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
}

bool compare_position(P a, P b)
{
    return (a.x < b.x) || (a.x == b.x && a.y > b.y); //left-top 
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