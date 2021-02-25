#include<bits/stdc++.h>
using namespace std;
int main(){
    int find = 5;
    int arr[] = {1,2,4,5,5,5,7,8};
    int left = -1;
    int right = 8;
    while(left < right -1)
    {
        int mid = (left+right)/2;
        if(arr[mid]>find)
            right = mid;
        else
            left = mid;
    }
    cout << right;
}


// int ctOutside=0;
    // for(int i = e;i>=b;i--){
    //     if(symbols[i] == ')') param++;
    //     else if(symbols[i] == '(') param--;
    //     if(param==0 && symbols[i]!='(') ctOutside++;
    // }
    // if(ctOutside > 0) {
    //     b++; e--;
    // }