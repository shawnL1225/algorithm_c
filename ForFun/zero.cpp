#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int arr[] = {5,3,2,8,9,7};
  int i=0;
  int j=0;
  while(1){
    if(i == 5) break;
    if(j>=6){
      i++;
      j=i;
    }
    if(arr[j] < arr[i]) swap(arr[i], arr[j]);
    j++;
  }

  for(int i=0;i<6;i++){
    cout <<arr[i];
  }
}

