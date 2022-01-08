#include <stdio.h>

int rec(int n){
    if(n==0 || n==1) return n+1;
    return rec(n-1) + rec(n/2);
}
int main(){
   
    int n;
    while(scanf("%d",&n) != EOF)
        printf("%d\n", rec(n));


    return 0;
}