#include <bits/stdc++.h>
using namespace std;
int sudo[9][9];
bool success;
int dfs(int y, int x){
    set<int> s;
    for(int i=0;i<9;i++){
        s.insert(sudo[y][i]);
    }
    for(int i=0;i<9;i++){
        s.insert(sudo[i][x]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            s.insert(sudo[(y/3)*3+i][(x/3)*3+j]);
        }
    }

    for(int i=1;i<=9;i++){
        if(s.count(i)==0){
            sudo[y][x] = i;

            bool end = 1;
            for(int ii=y; ii<9; ii++){
                for(int jj=0; jj<9; jj++){
                    if(sudo[ii][jj]==0){
                        end = 0;
                        if(dfs(ii,jj))
                            return 1;
                            goto next;
                    }
                        
                }
            }
            next:
            if(end) {success = 1; return 1;}
            sudo[y][x] = 0;

        }
    }
    return 0;
}
int main(){
    for(int i=0; i<9; i++){
        for(int j=0;j<9;j++){
            cin >> sudo[i][j];
        }
    }
    // cout << endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(sudo[i][j] == 0)
                dfs(i,j);
        }
    }

    for(int i=0;i<9;i++){
        for(int j=0; j<9; j++){
            cout << sudo[i][j];
        }
        cout << endl;
    }

}

// 3 0 6 5 0 8 4 0 0 
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0