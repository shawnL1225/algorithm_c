#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10,k;
    int A[n] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 9};
    int left = -1, right = n;
    cin >> k;
    while(left < right -1)
    {
        int mid = (left+right)/2;
        if(A[mid] <= k)
            left = mid;
        else
            right = mid;
    }
    cout << "pos: " << left;

}