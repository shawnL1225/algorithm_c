#include<stdio.h>
int main(){
    int a;
    while(scanf("%d", &a) !=EOF){
       printf("%d days\n", a/(60*60*24));
       a%=(60*60*24);
       printf("%d hours\n", a/(3600));
       a%=3600;
       printf("%d minutes\n", a/60);
       a%=60;
       printf("%d seconds\n", a);
    }
    
        
}