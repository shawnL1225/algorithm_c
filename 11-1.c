/*  probID: 11-1-Explore  */

#define MAX_N 50
#define MAX_M 50

int n, m;
char grid_map[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

// 上、下、左、右 四個探索方向
int dir[4][2] = {
    {1,0}, {-1,0}, {0,-1}, {0,1}
};

void Explore(int x,int y)
{
    visited[x][y] = 1;

    for(int i=0;i<=3;i++)   // 考慮 (x,y) 周圍上、下、左、右四個方向
    {
        if( x+dir[i][0]>=0 && x+dir[i][0]<m && y+dir[i][1] >=0 && y+dir[i][1]<n && grid_map[x+dir[i][0]][y+dir[i][1]] == '.' && !visited[x+dir[i][0]][y+dir[i][1]])
            Explore( x+dir[i][0], y+dir[i][1] );
    }
}

