#include <iostream>
using namespace std;
int main()
{
    int f[45], n;
    f[0] = 0;
    f[1] = 1;

    cin >> n;
    for(int i = 2;i<=n;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    cout << f[n];
};