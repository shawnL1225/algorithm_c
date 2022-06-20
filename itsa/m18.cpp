#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int ind = 1;
        ind <<= 7;
        for(int i=0;i<8;i++){
            n&ind? cout << 1:cout << 0;
            ind >>= 1;
            
        }
        printf("\n");
    }
    
}