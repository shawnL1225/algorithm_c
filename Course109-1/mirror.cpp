#include <bits/stdc++.h>
using namespace std;
int m,n;
int arr[105][105];
int dirTRDL[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int stat[2];

void margin()
{
    int margin = 0;
    for(int i=1;i<=m;i++, margin++)
    {
        arr[n+1][i] = margin;
    }
    for(int i=n;i>=1;i--, margin++)
    {
        arr[i][m+1] = margin;
    }
    for(int i=m;i>=1;i--, margin++)
    {
        arr[0][i] = margin;
    }
    for(int i=1;i<=n;i++, margin++)
    {
        arr[i][0] = margin;
    }
}
void dfs(int y, int x){
    int t = 0;
    while(1){
        if(arr[y][x] > 1 || (arr[y][x]<=1 && y == n+1)) {
            cout << arr[y][x] <<endl;
            break;
        }
        if(arr[y][x] == 1)
        {
            t = (t+1)%2;
        }
        // cout <<stat[t] <<"y: " << dirTRDL[stat[t]][0] << ' ' << dirTRDL[stat[t]][1] << ' ' << arr[y][x] << endl;
        y+=dirTRDL[stat[t]][0]; 
        x+=dirTRDL[stat[t]][1];
    }
}
void reflect()
{
    for(int i=1;i<=m;i++)
    {
        //0 是一開始的方向
        stat[0] = 0; stat[1] = 1;
        dfs(n+1+dirTRDL[stat[0]][0],i+dirTRDL[stat[0]][1]);
    }
    for(int i=n;i>=1;i--)
    {
        stat[0] = 3; stat[1] = 2;
        dfs(i+dirTRDL[stat[0]][0],m+1+dirTRDL[stat[0]][1]);
    }
    for(int i=m;i>=1;i--)
    {
        stat[0] = 2; stat[1] = 3;
        dfs(0+dirTRDL[stat[0]][0],i+dirTRDL[stat[0]][1]);
    }
    for(int i=1;i<=n;i++)
    {
        stat[0] = 1; stat[1] = 0;
        dfs(i+dirTRDL[stat[0]][0],0+dirTRDL[stat[0]][1]);
    }
}
int main(){
    cin >> m >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> arr[i][j];

    margin();
    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<=m+1;j++)
    //         cout << arr[i][j]<< ' ';
    //     cout << '\n';
    // }
    reflect();

}