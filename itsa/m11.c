#include<stdio.h>
int main(){
    int a;
    while(scanf("%d", &a) !=EOF){
       printf("NT10=%d\n", a/10);
       a%=10;
       printf("NT5=%d\n", a/5);
       a%=5;
       printf("NT1=%d\n", a);
    }
    
        
}