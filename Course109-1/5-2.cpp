#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int orin = n;
    for(int i=2;i<orin/2;i++) {
        int ct = 0;
        while(n%i == 0){
            n/=i;
            ct++;
        }
        if(ct > 0){
            cout << i << ' '<< ct << endl;
        }

        if(n==1) break;
    }
    
      

    return 0;
}