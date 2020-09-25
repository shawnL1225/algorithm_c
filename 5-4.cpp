#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    for(;i<n;i++)
        cin >> arr[i];

    for(i--;i>-1;i--)
        cout << arr[i] <<' ';
    
      //hi 

    return 0;
}