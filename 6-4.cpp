#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct P
{
    int x;
    int y;
};

int main(){
    int n;
    cin >> n;
    long long int cal=0, max=0;
    P arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].x >> arr[i].y;
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++){
            cal = pow(arr[i].x-arr[j].x,2) + pow(arr[i].y-arr[j].y,2);
            cal = (arr[i].x-arr[j].x)*(arr[i].x-arr[j].x) + (arr[i].y-arr[j].y)*(arr[i].y-arr[j].y);
            if(cal > max){
                max = cal;
            }
                
        }
    }
    double d = sqrt(max);
    cout << fixed << setprecision(0) << d;
}