#include <bits/stdc++.h>

using namespace std;
int n,k;
int arr[101][101],arr2[101][101],live[101][101];
int dir[8][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};

void neighbor(int y,int x)
{
    int ct=0;
    for(int i=0;i<8;i++)
    {
        if(y+dir[i][0]>=0 && x+dir[i][1]>=0  && arr[y+dir[i][0]][x+dir[i][1]] == 1) ct++;
    }
    if(arr[y][x] == 1)
    {
        if(ct<2 || ct>3) arr2[y][x] = 0;
        else{
            live[y][x] +=1 ;
        }
    }
    else
    {
        if(ct==3) 
        {
            arr2[y][x] = 1;
            live[y][x] +=1;
        }
    }

}
int main()
{
    memset(live,0,sizeof(live));
    cin >> n>>k;
    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
            arr2[i][j] = arr[i][j];
            if(arr[i][j] == 1) live[i][j] +=1;
        }
    }
    
       
    while(k--){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                neighbor(i,j);
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                arr[i][j] = arr2[i][j];

        
    }

    // cout << "\n";
    int bigest =0,y,x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr2[i][j]<<' ';
            if(live[i][j] >= bigest)
            {
                bigest = live[i][j];
                y = i; x = j;
            }
        }
            
        cout << "\n";
    }

    cout << y+1<< ' '<<x+1;

    
    



}
