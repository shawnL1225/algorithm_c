#include <iostream>
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    long long unsigned int top = 1, down = 1;

    int j = 2;
    for(int i = k+1;i<=n;i++) {
        top *= i;

        while(top%j==0 && j<=n-k){
            top /= j;
            j++;
        }
    }

    long long unsigned int ans = top/down;
    cout << ans;
    return 0;
}