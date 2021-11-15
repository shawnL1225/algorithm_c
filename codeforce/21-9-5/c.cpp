#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
int n;
struct C{
    lint dir,id;
};
struct S{
    lint val,id;
};

C arrR[100005];
C arrG[100005];
C arrB[10005];
S sum[100005];
lint identity[100005];
bool comp(C a,C b){
    return a.dir < b.dir;
}
bool compS(S a,S b){
    if(a.val == b.val) return identity[a.id] > identity[b.id];
    return a.val < b.val;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arrR[i].dir >> arrG[i].dir >> arrB[i].dir >> identity[i];
        arrR[i].id=i;
        arrG[i].id=i;
        arrB[i].id=i;
        
        
    }
    sort(arrR,arrR+n,comp);
    sort(arrG,arrG+n,comp);
    sort(arrB,arrB+n,comp);
    int id=0;
    for(int i=1;i<n-1;i++){
        if(arrR[i].dir != arrR[i-1].dir  &&   arrR[i].dir != arrR[i+1].dir){
            id = arrR[i].id;
            sum[id].val +=  arrR[i+1].dir - arrR[i-1].dir;
        }
        if(arrB[i].dir != arrB[i-1].dir  &&   arrB[i].dir != arrB[i+1].dir){
            id = arrB[i].id;
            sum[id].val +=  arrB[i+1].dir - arrB[i-1].dir;
        }
        if(arrG[i].dir != arrG[i-1].dir  &&   arrG[i].dir != arrG[i+1].dir){
            id = arrG[i].id;
            sum[id].val +=  arrG[i+1].dir - arrG[i-1].dir;
         }
        
    }
    
    if(arrR[0].dir != arrR[1].dir ){
        id = arrR[0].id;
        sum[id].val += arrR[1].dir - arrR[n-1].dir + 360;
    }
    if(arrG[0].dir != arrG[1].dir ){
         id = arrG[0].id;
        sum[id].val += arrG[1].dir - arrG[n-1].dir + 360;
    }
    if(arrB[0].dir != arrB[1].dir ){
        id = arrB[0].id;
        sum[id].val += arrB[1].dir - arrB[n-1].dir + 360;
    }
    
    
    if(arrR[n-1].dir != arrR[n-2].dir ){
        id = arrR[n-1].id;
        sum[id].val += arrR[0].dir - arrR[n-2].dir + 360;
    }
    if(arrB[n-1].dir != arrB[n-2].dir ){
        id = arrB[n-1].id;
        sum[id].val += arrB[0].dir - arrB[n-2].dir + 360;
    }
    if(arrG[n-1].dir != arrG[n-2].dir ){
        id = arrG[n-1].id;
        sum[id].val += arrG[0].dir - arrG[n-2].dir + 360;
    }
    
    // for(int i=0;i<n;i++){
    //     cout << arrR[i].dir << ' ' << arrG[i].dir <<' ' << arrB[i].dir << endl;
    // }cout << endl;
    
    // for(int i=0;i<n;i++){
    //     cout << sum[i].val<<' ';
    // }
   
    //sum id 
    for(int i=0;i<n;i++){
        sum[i].id = i;
    }


    sort(sum,sum+n,compS);
    for(int i=0;i<n;i++){
        cout << identity[ sum[i].id ]<< endl;
    }
    


    return 0;
}