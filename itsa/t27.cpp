#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ans;
    string input;

    cin >> ans;
    while(cin >> input){
        if(input == "0000") return 0;
        int ctA=0,ctB=0;
        int len = ans.length();
        for(int i=0; i<len; i++){
            if(ans[i] == input[i]) {
                ctA++;
                input[i] = '*';
            }
        }

        for(int i=0; i<len; i++){
            if(input[i] == '*') continue;
            
            for(int j=0; j<len; j++){
                if(input[j] == '*') continue;
                if(ans[i] == input[j]){
                    ctB++;
                    input[j] = '^';
                }
            }
        }
        
        // if(ctA == 4) {
        //     cout << "congrats !"<<endl;
        //     return 0;
        // }
        // else
            cout << ctA << 'A' << ctB << "B\n";
    }
}