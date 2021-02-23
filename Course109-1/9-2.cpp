#include <bits/stdc++.h>
using namespace std;
char maze[105][105];
int n,m,ct=0;
void check(int y,int x){
    if(y-1 >=0 && maze[y-1][x] == '@') {ct++; maze[y-1][x] = 'x';}
    if(maze[y+1][x] == '@') {ct++;maze[y+1][x] = 'x';}
    if(x-1>=0 && maze[y][x-1] == '@'){ct++; maze[y][x-1] = 'x';}
    if(maze[y][x+1] == '@') {ct++; maze[y][x+1] = 'x';} 
}

int main(){

    cin >> n >>m;
    
    for(int i=0;i<n;i++)
        cin >> maze[i];


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if( maze[i][j] == '+'){
                check(i,j);
            }
                
        }
    }

    cout << ct <<endl;



    
    

}