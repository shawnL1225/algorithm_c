#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        printf("1");
        for(int i=2;i<=n;i++){
           if(n%i==0){
               printf(" %d", i);
           }
        }
        printf("\n");
    }
}