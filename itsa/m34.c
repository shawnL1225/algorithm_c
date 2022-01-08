#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        for(int i=1;i<=n;i++){
           if(n%i==0){
               printf("%d ", i);
           }
        }
        printf("\n");
    }
}