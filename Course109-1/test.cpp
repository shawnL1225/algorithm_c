#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ans;
    string input;
    cout << "input ans: "<<endl;
    cin >> ans;
    while(cin >> input){
        int ctA=0,ctB=0;

        for(int i=0;i<4;i++){
            if(ans[i] == input[i]) {
                ctA++;
                input[i] = '*';
            }
        }

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j) continue;
                if(ans[i] == input[j]){
                    ctB++;
                    input[j] = '*';
                }
            }
        }
        
        if(ctA == 4) {
            cout << "congrats !"<<endl;
            return 0;
        }
        else
            cout << ctA << 'A' << ctB << 'B'<<endl;
    }
}