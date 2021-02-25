#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr[505];
    int n,m,num,ctAns=0;  //n->row , m->col
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> num;
            arr[i].push_back(num);
        }
    }

    int top = 0;
    for(int leadCol = 0; leadCol<n; leadCol++, top++){
        int choose = top;
        while(choose < m && arr[choose][leadCol] == 0) choose++;
        if(choose == m) {
            top--;
            continue;
        }
        
        
        swap(arr[choose],arr[top]);
        for(int task = top+1; task<m; task++){
            if(arr[task][leadCol] == 1){
                for(int i=0;i<n;i++){
                    arr[task][i] = (arr[task][i]+arr[top][i])%2;
                }
            }
            
        }
        // cout << leadCol <<choose<<endl;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout << arr[i][j]<< ' ';
        //     }
        //     cout <<endl;
        // }
    }

    vector<int> zero;
    for(int i=0;i<n;i++)
        zero.push_back(0);
    for(int i=0;i<m;i++){
        if(arr[i] == zero) ctAns++;
    }
    cout << m-ctAns<<endl;
    
        


}