#include <bits/stdc++.h>
using namespace std;
char maze[105][105];
int n,m,ansx=0,ansy=0,ansn=0,power;
int check(int y,int x){
    int ct=0;
    int oy = y,ox = x;
    for(int i=0;i<power;i++){
        if(y-1 >=0 && maze[y-1][x] == '@') ct++;
        else if(y-1 >=0 && maze[y-1][x] == '#') break;
        y--;
    }
    y = oy;x = ox;
    for(int i=0;i<power;i++){
        if(y+1 <= n-1 && maze[y+1][x] == '@') ct++;
        else if(y+1 <= n-1 && maze[y+1][x] == '#') break;
        y++;
    } 
    y = oy;x = ox;
    for(int i=0;i<power;i++){
        if(x-1>=0 && maze[y][x-1] == '@') ct++;
        else if(x-1>=0 && maze[y][x-1] == '#') break;
        x--;
    }
    y = oy;x = ox;
    for(int i=0;i<power;i++){
        if(maze[y][x+1] == '@') ct++;
        else if(maze[y][x+1] == '#') break;
        x++;
    }

    return ct;
    
    
}

int main(){

    cin >> n >>m;
    
    for(int i=0;i<n;i++)
        cin >> maze[i];
    cin >> power;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if( maze[i][j] == '.'){
                int checkv = check(i,j);
                if(checkv>=ansn)
                {
                    ansn = checkv;
                    ansx = j;
                    ansy = i;
                }
            }
                
        }
    }
    // if(ansn == 0){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(maze[i][j] == '.')
    //             {
                    
    //                ansy=i;
    //                ansx=j;
    //                 goto end;
    //             }
    //         }
    //     }
            
    // }
    // end:

    cout << ansy <<' '<<ansx <<endl;
    cout << ansn;



    
    

}