#include <stdio.h>
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        double pay ;
        if(n >=1500){
           pay = n*0.9*0.79;
        }
        else if(n>800){
           pay = n*0.9*0.9;
        }
        else {
            pay = n*0.9;
        }
        printf("%.1lf\n", pay);
    }
    
}