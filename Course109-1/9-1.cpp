#include <bits/stdc++.h>
using namespace std;
char maze[105][105];
int n,m;
struct P
{
    int x;
    int y;
};
P start;

void R(){
    if(maze[start.y][start.x+1] == '.') start.x++;
}
void L(){
    if(start.x-1 >=0 && maze[start.y][start.x-1] == '.') start.x--;
}
void U(){
    if(start.y-1 >=0 && maze[start.y-1][start.x] == '.') start.y--;
}
void D(){
    if(maze[start.y+1][start.x] == '.') start.y++;
}

int main(){

    cin >> n >>m;
    
    for(int i=0;i<n;i++)
        cin >> maze[i];
    cin >> start.y >> start.x;



    string s;
    cin >> s;
    for(int i=0;i<(signed)s.length();i++)
    {
        if(s[i] == 'R') R();
        else if(s[i] == 'U') U();
        else if(s[i] == 'D') D();
        else if(s[i] == 'L') L();
    }

    cout << start.y << ' '<<start.x;

    

}