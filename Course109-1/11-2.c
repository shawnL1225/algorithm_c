#include <stdio.h>

 int n,m;
 char grid_map[50][50];
 int visited[50][50];

void Explore(int,int);

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
    {
        char tmp[100];
        scanf("%s", tmp);

        for(int j=0; j<m; j++)
        {
            grid_map[i][j] = tmp[j];
            visited[i][j] = 0;
        }
    }

    int init_x, init_y;
    scanf("%d%d", &init_x, &init_y);

    Explore(init_x,init_y);

    int end_x, end_y;
    scanf("%d%d", &end_x, &end_y);

    if(visited[end_x][end_y]) printf("Yes");
    else printf("No");

    return 0;
}



// 上、下、左、右 四個探索方向
int dir[4][2] = {
    {1,0}, {-1,0}, {0,-1}, {0,1}
};

void Explore(int x,int y)
{
    visited[x][y] = 1;

    for(int i=0;i<=3;i++)   // 考慮 (x,y) 周圍上、下、左、右四個方向
    {
        if( x+dir[i][0]>=0 && x+dir[i][0]<n && y+dir[i][1] >=0 && y+dir[i][1]<m && grid_map[x+dir[i][0]][y+dir[i][1]] == '.' && !visited[x+dir[i][0]][y+dir[i][1]])
            Explore( x+dir[i][0], y+dir[i][1] );
    }
}


