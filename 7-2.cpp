#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
        cin >> A[i];
 

    int buff;

    for(int i=0;i<n-1;i++){
        int min = A[i],minP = i;
        for(int j=i;j<n;j++){
            if(A[j] < min){
                min = A[j];
                minP = j;
            }
        }
        // cout << min<<endl;
        swap(A[i],A[minP]);
        
        // A[minP] = A[i];
        // A[i] = min;
    }
        

    for(int i=0;i<n;i++)
        cout << A[i] << ' ';

    return 0;
};